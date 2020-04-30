#include "GameApp.h"
#include "d3dUtil.h"
#include "DXTrace.h"
#include"Camera.h"
using namespace DirectX;

GameApp::GameApp(HINSTANCE hInstance)
	: D3DApp(hInstance),
	m_CameraMode(CameraMode::Free),
	m_SkyBoxMode(SkyBoxMode::Daylight)
{
}

GameApp::~GameApp()
{
}

bool GameApp::Init()
{
	if (!D3DApp::Init())
		return false;

	// 务必先初始化所有渲染状态，以供下面的特效使用
	RenderStates::InitAll(m_pd3dDevice.Get());

	if (!m_BasicEffect.InitAll(m_pd3dDevice.Get()))
		return false;

	if (!m_SkyEffect.InitAll(m_pd3dDevice.Get()))
		return false;

	if (!InitResource())
		return false;

	// 初始化鼠标，键盘不需要
	m_pMouse->SetWindow(m_hMainWnd);
	m_pMouse->SetMode(DirectX::Mouse::MODE_RELATIVE);

	return true;
}

void GameApp::OnResize()
{
	assert(m_pd2dFactory);
	assert(m_pdwriteFactory);
	// 释放D2D的相关资源
	m_pColorBrush.Reset();
	m_pd2dRenderTarget.Reset();

	D3DApp::OnResize();

	// 为D2D创建DXGI表面渲染目标
	ComPtr<IDXGISurface> surface;
	HR(m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), reinterpret_cast<void**>(surface.GetAddressOf())));
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));
	HRESULT hr = m_pd2dFactory->CreateDxgiSurfaceRenderTarget(surface.Get(), &props, m_pd2dRenderTarget.GetAddressOf());
	surface.Reset();

	if (hr == E_NOINTERFACE)
	{
		OutputDebugStringW(L"\n警告：Direct2D与Direct3D互操作性功能受限，你将无法看到文本信息。现提供下述可选方法：\n"
			L"1. 对于Win7系统，需要更新至Win7 SP1，并安装KB2670838补丁以支持Direct2D显示。\n"
			L"2. 自行完成Direct3D 10.1与Direct2D的交互。详情参阅："
			L"https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/direct2d-and-direct3d-interoperation-overview""\n"
			L"3. 使用别的字体库，比如FreeType。\n\n");
	}
	else if (hr == S_OK)
	{
		// 创建固定颜色刷和文本格式
		HR(m_pd2dRenderTarget->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::White),
			m_pColorBrush.GetAddressOf()));
		HR(m_pdwriteFactory->CreateTextFormat(L"宋体", nullptr, DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 15, L"zh-cn",
			m_pTextFormat.GetAddressOf()));
	}
	else
	{
		// 报告异常问题
		assert(m_pd2dRenderTarget);
	}

	// 摄像机变更显示
	if (m_pCamera != nullptr)
	{
		m_pCamera->SetFrustum(XM_PI / 3, AspectRatio(), 1.0f, 1000.0f);
		m_pCamera->SetViewPort(0.0f, 0.0f, (float)m_ClientWidth, (float)m_ClientHeight);
		m_BasicEffect.SetProjMatrix(m_pCamera->GetProjXM());
	}
}

void GameApp::UpdateScene(float dt)
{

	// 更新鼠标事件，获取相对偏移量
	Mouse::State mouseState = m_pMouse->GetState();
	Mouse::State lastMouseState = m_MouseTracker.GetLastState();
	m_MouseTracker.Update(mouseState);

	Keyboard::State keyState = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keyState);

	auto cam1st = std::dynamic_pointer_cast<FirstPersonCamera>(m_pCamera);

	// ******************
	// 自由摄像机的操作
	//

	// 方向移动
	if (keyState.IsKeyDown(Keyboard::W))
		cam1st->MoveForward(dt * 3.0f);
	if (keyState.IsKeyDown(Keyboard::S))
		cam1st->MoveForward(dt * -3.0f);
	if (keyState.IsKeyDown(Keyboard::A))
		cam1st->Strafe(dt * -3.0f);
	if (keyState.IsKeyDown(Keyboard::D))
		cam1st->Strafe(dt * 3.0f);
	if (keyState.IsKeyDown(Keyboard::Space))
		cam1st->Up(dt * 5.0f);
	if (keyState.IsKeyDown(Keyboard::LeftShift)||keyState.IsKeyDown(Keyboard::RightShift))
		cam1st->Up(dt * -5.0f);

	XMFLOAT3 adjustedPos;
	XMStoreFloat3(&adjustedPos, XMVectorClamp(cam1st->GetPositionXM(), XMVectorSet(-25.0f, -3.9f, -25.0f, 0.0f), XMVectorReplicate(25.0f)));
	cam1st->SetPosition(adjustedPos);

	XMFLOAT3 look;
	XMStoreFloat3(&look,cam1st->GetLookXM());

	// 视野旋转，防止开始的差值过大导致的突然旋转
	cam1st->Pitch(mouseState.y * dt * 1.25f);
	cam1st->RotateY(mouseState.x * dt * 1.25f);

	// 更新观察矩阵
	m_pCamera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(m_pCamera->GetViewXM());
	m_BasicEffect.SetEyePos(m_pCamera->GetPositionXM());

	// 重置滚轮值
	m_pMouse->ResetScrollWheelValue();



	// 选择天空盒
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D1))
	{
		m_SkyBoxMode = SkyBoxMode::Daylight;
		m_BasicEffect.SetTextureCube(m_pDaylight->GetTextureCube());
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D2))
	{
		m_SkyBoxMode = SkyBoxMode::Sunset;
		m_BasicEffect.SetTextureCube(m_pSunset->GetTextureCube());
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::D3))
	{
		m_SkyBoxMode = SkyBoxMode::Desert;
		m_BasicEffect.SetTextureCube(m_pDesert->GetTextureCube());
	}
	m_PickedObjStr = L"无";
	Ray ray = Ray::ScreenToRay(*m_pCamera, 382.5f, 280.0f);

	bool hitObject = false;
	static bool temp1 = false;
	static bool temp2 = false;
	static bool temp3 = false;

	static bool look1 = false;
	static bool look2 = false;
	static bool look3 = false;

	if (ray.Hit(m_BoundingSphere1))
	{
		m_PickedObjStr = L"球体1";
		hitObject = true;
	}
	if (ray.Hit(m_BoundingSphere3))
	{
		m_PickedObjStr = L"球体3";
		hitObject = true;
	}	
	if (ray.Hit(m_BoundingSphere2))
	{
		m_PickedObjStr = L"球体2";
		hitObject = true;
	}
	else if (ray.Hit(m_Cylinder1.GetBoundingOrientedBox())
		|| ray.Hit(m_Cylinder2.GetBoundingOrientedBox())|| ray.Hit(m_Cylinder3.GetBoundingOrientedBox()))
	{
		m_PickedObjStr = L"圆柱";
		hitObject = true;
	}

	//碰撞检测
	m_TouchObjStr = L"    ";
	if(m_BoundingSphere1.Intersects(m_Cylinder1.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq1draw = 0;
		cy1draw = 0;

	}
	if(m_BoundingSphere1.Intersects(m_Cylinder2.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq1draw = 0;
		cy2draw = 0;

	}
	if(m_BoundingSphere1.Intersects(m_Cylinder3.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq1draw = 0;
		cy3draw = 0;

	}
	if(m_BoundingSphere2.Intersects(m_Cylinder1.GetBoundingOrientedBox())) 
	{ 
		m_TouchObjStr = L"碰撞！";
		sq2draw = 0;
		cy1draw = 0;

	}
	if(m_BoundingSphere2.Intersects(m_Cylinder2.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq2draw = 0;
		cy2draw = 0;

	}
	if(m_BoundingSphere2.Intersects(m_Cylinder3.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq2draw = 0;
		cy3draw = 0;

	}
	if(m_BoundingSphere3.Intersects(m_Cylinder1.GetBoundingOrientedBox())) 
	{
		m_TouchObjStr = L"碰撞！";
		sq3draw = 0;
		cy1draw = 0;

	}
	if(m_BoundingSphere3.Intersects(m_Cylinder2.GetBoundingOrientedBox())) 
	{
		m_TouchObjStr = L"碰撞！";
		sq3draw = 0;
		cy2draw = 0;

	}
	if(m_BoundingSphere3.Intersects(m_Cylinder3.GetBoundingOrientedBox()))
	{
		m_TouchObjStr = L"碰撞！";
		sq3draw = 0;
		cy3draw = 0;

	}


	//选取物体
	if(hitObject == true && m_MouseTracker.leftButton == m_MouseTracker.HELD)
	{
		if (ray.Hit(m_BoundingSphere1))
		{
			m_Sphere1.SetWorldMatrix(XMMatrixTranslation(adjustedPos.x + 3 * look.x, adjustedPos.y + 3 * look.y, adjustedPos.z + 3 * look.z));
			m_BoundingSphere1.Center = m_Sphere1.GetPosition();
		}

		if (ray.Hit(m_BoundingSphere2))
		{
			m_Sphere2.SetWorldMatrix(XMMatrixTranslation(adjustedPos.x + 3 * look.x, adjustedPos.y + 3 * look.y, adjustedPos.z + 3 * look.z));
			m_BoundingSphere2.Center = m_Sphere2.GetPosition();
		}
		if (ray.Hit(m_BoundingSphere3))
		{
			m_Sphere3.SetWorldMatrix(XMMatrixTranslation(adjustedPos.x + 3 * look.x, adjustedPos.y + 3 * look.y, adjustedPos.z + 3 * look.z));
			m_BoundingSphere3.Center = m_Sphere3.GetPosition();
		}
	}


if (m_Sphere2.GetPosition().y < m_Ground.GetPosition().y)
{
	temp2 = false;
}
if (m_Sphere3.GetPosition().y < m_Ground.GetPosition().y)
{
	temp3 = false;
}



	//物体投掷
	if (mouseState.rightButton == true && m_MouseTracker.rightButton == m_MouseTracker.PRESSED)
	{
		if (ray.Hit(m_BoundingSphere1))
		{
			temp1 = true;
			look1 = true;
		}
		if (ray.Hit(m_BoundingSphere2))
		{
			temp2 = true;
			look2 = true;
		}
		if (ray.Hit(m_BoundingSphere3))
		{
			temp3 = true;
			look3 = true;
		}
	}
	static double speed1 = 0.0f;
	if (temp1 )
	{

		static XMFLOAT3 posL1 = cam1st->GetLook();
		XMFLOAT3 pos1 = m_Sphere1.GetPosition();
		if (look1)
		{
			posL1 = cam1st->GetLook();
			look1 = false;
		}
		speed1 -= 0.00002f;
		m_Sphere1.SetWorldMatrix(XMMatrixTranslation(pos1.x + 0.02* posL1.x, speed1+pos1.y + 0.02 * posL1.y, pos1.z + 0.02* posL1.z));
		m_BoundingSphere1.Center = m_Sphere1.GetPosition();
		if (m_Sphere1.GetPosition().y < m_Ground.GetPosition().y)
		{
			m_Sphere1.SetWorldMatrix(XMMatrixTranslation(0.0f, -4.3f, -7.0f));
			m_BoundingSphere1.Center = m_Sphere1.GetPosition();
			temp1 = false;
			look1 = true;
			speed1 = 0.0f;
		}
	}

	static double speed2 = 0.0f;
	if (temp2)
	{
		static XMFLOAT3 posL2 = cam1st->GetLook();
		XMFLOAT3 pos2 = m_Sphere2.GetPosition();
		if (look2)
		{
			posL2 = cam1st->GetLook();
			look2 = false;
		}
		speed2 -= 0.00002f;
		m_Sphere2.SetWorldMatrix(XMMatrixTranslation(pos2.x + 0.02 * posL2.x, speed2 + pos2.y + 0.02 * posL2.y, pos2.z + 0.02 * posL2.z));
		m_BoundingSphere2.Center = m_Sphere2.GetPosition();
		if (m_Sphere2.GetPosition().y < m_Ground.GetPosition().y)
		{
			m_Sphere2.SetWorldMatrix(XMMatrixTranslation(3.0f, -4.3f, -7.0f));
			m_BoundingSphere2.Center = m_Sphere2.GetPosition();
			temp2 = false;
			look2 = true;
			speed2 = 0.0f;
		}
	}

	static double speed3 = 0.0f;
	if (temp3)
	{
		static XMFLOAT3 posL3 = cam1st->GetLook();
		XMFLOAT3 pos3 = m_Sphere3.GetPosition();
		if (look3)
		{
			posL3 = cam1st->GetLook();
			look3 = false;
		}
		speed3 -= 0.00002f;
		m_Sphere3.SetWorldMatrix(XMMatrixTranslation(pos3.x + 0.02 * posL3.x, speed3 + pos3.y + 0.02 * posL3.y, pos3.z + 0.02 * posL3.z));
		m_BoundingSphere3.Center = m_Sphere3.GetPosition();
		if (m_Sphere3.GetPosition().y < m_Ground.GetPosition().y)
		{
			m_Sphere3.SetWorldMatrix(XMMatrixTranslation(-3.0f, -4.3f, -7.0f));
			m_BoundingSphere3.Center = m_Sphere3.GetPosition();
			temp3 = false;
			look3 = true;
			speed3 = 0.0f;
		}
	}


	m_pMouse->ResetScrollWheelValue();

	// 退出程序，这里应向窗口发送销毁信息
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Escape))
		SendMessage(MainWnd(), WM_DESTROY, 0, 0);


	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);

	// ******************
	// 绘制Direct3D部分
	//
	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), reinterpret_cast<const float*>(&Colors::Black));
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// 绘制模型

	m_BasicEffect.SetRenderDefault(m_pd3dImmediateContext.Get(), BasicEffect::RenderObject);
	m_BasicEffect.SetReflectionEnabled(true);
	m_BasicEffect.SetTextureUsed(true);
	if (sq1draw)
	{
		m_Sphere1.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	}
	if (sq2draw)
	{
		m_Sphere2.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	}
	if (sq3draw)
	{
		m_Sphere3.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	}


	m_BasicEffect.SetReflectionEnabled(false);
		m_Ground.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	if (cy1draw)
		m_Cylinder1.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	if (cy2draw)
		m_Cylinder2.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);
	if (cy3draw)
		m_Cylinder3.Draw(m_pd3dImmediateContext.Get(), m_BasicEffect);

	// 绘制天空盒
	m_SkyEffect.SetRenderDefault(m_pd3dImmediateContext.Get());
	switch (m_SkyBoxMode)
	{
	case SkyBoxMode::Daylight: m_pDaylight->Draw(m_pd3dImmediateContext.Get(), m_SkyEffect, *m_pCamera); break;
	case SkyBoxMode::Sunset: m_pSunset->Draw(m_pd3dImmediateContext.Get(), m_SkyEffect, *m_pCamera); break;
	case SkyBoxMode::Desert: m_pDesert->Draw(m_pd3dImmediateContext.Get(), m_SkyEffect, *m_pCamera); break;
	}

}

void GameApp::DrawScene()
{
	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);
	// ******************
	// 绘制Direct2D部分
	//
	if (m_pd2dRenderTarget != nullptr)
	{
		m_pd2dRenderTarget->BeginDraw();
		std::wstring text = L"当前摄像机模式: 自由视角  Esc退出\n"
			L"鼠标移动控制视野 W/S/A/D移动 空格上升shift下降 \n"
			L"对准球左键可以选取，对球点击右键可以发射\n"
			L"切换天空盒: 1-湖面清晨 2-未知星球之夜 3-雪山\n"
			L"当前天空盒: ";

		switch (m_SkyBoxMode)
		{
		case SkyBoxMode::Daylight: text += L"湖面清晨"; break;
		case SkyBoxMode::Sunset: text += L"未知星球之夜"; break;
		case SkyBoxMode::Desert: text += L"雪山"; break;
		}
		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.length(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 0.0f, 0.0f, 600.0f, 200.0f }, m_pColorBrush.Get());


		text = L"2020QG工作室图形组第5次小组培训\n"
			L"                         叶铭韬\n"
			L"                  2020年4月30日\n"
			L"            当前指向物体: " + m_PickedObjStr;
		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.size(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 565.0f, 0.0f, 900.0f, 500.0f }, m_pColorBrush.Get());

		text = L"                  状态：" + m_TouchObjStr;
		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.size(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 565.0f, 70.0f, 900.0f, 500.0f }, m_pColorBrush.Get());

		text = L"╋\n";

		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.size(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 382.5f, 280.0f, 600.0f, 500.0f }, m_pColorBrush.Get());

		HR(m_pd2dRenderTarget->EndDraw());
	}

	HR(m_pSwapChain->Present(0, 0));
}



bool GameApp::InitResource()
{
	// ******************
	// 初始化天空盒相关

	m_pDaylight = std::make_unique<SkyRender>();
	HR(m_pDaylight->InitResource(m_pd3dDevice.Get(), m_pd3dImmediateContext.Get(),
		std::vector<std::wstring>{
		L"Texture\\chenwu_L.jpg", L"Texture\\chenwu_R.jpg", 
			L"Texture\\chenwu_U.jpg", L"Texture\\chenwu_D.jpg",
			L"Texture\\chenwu_F.jpg", L"Texture\\chenwu_B.jpg", }, 
		5000.0f));

	m_pSunset = std::make_unique<SkyRender>();
	HR(m_pSunset->InitResource(m_pd3dDevice.Get(), m_pd3dImmediateContext.Get(),
		std::vector<std::wstring>{
		L"Texture\\Outer_space_posX.png", L"Texture\\Outer_space_negX.png",
			L"Texture\\Outer_space_posY.png", L"Texture\\Outer_space__negY.png",
			L"Texture\\Outer_space__negZ.png", L"Texture\\Outer_space__posZ.png", }, 
		5000.0f));

	m_pDesert = std::make_unique<SkyRender>();
	HR(m_pDesert->InitResource(m_pd3dDevice.Get(), m_pd3dImmediateContext.Get(),
		std::vector<std::wstring>{
		L"Texture\\negx.jpg", L"Texture\\posx.jpg", 
			L"Texture\\negy.jpg", L"Texture\\posy.jpg",
			L"Texture\\negz.jpg", L"Texture\\posz.jpg", },
		5000.0f));

	m_BasicEffect.SetTextureCube(m_pDaylight->GetTextureCube());
	// ******************
	// 初始化游戏对象
	//
	
	Model model;
	// 球体1
	model.SetMesh(m_pd3dDevice.Get(), Geometry::CreateSphere(0.7f, 30, 30));

	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\floor.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Sphere1.SetModel(std::move(model));
	m_BoundingSphere1.Center = XMFLOAT3(0.0f, -4.3f, -7.0f);
	m_BoundingSphere1.Radius = 1.0f;
	m_Sphere1.SetWorldMatrix(XMMatrixTranslation(0.0f, -4.3f, -7.0f));

	// 球体2
	model.SetMesh(m_pd3dDevice.Get(), Geometry::CreateSphere(0.7f, 30, 30));
	m_BoundingSphere2.Center = XMFLOAT3(-5.0f, 0.0f, 0.0f);
	m_BoundingSphere2.Radius = 1.0f;
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\floor.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Sphere2.SetModel(std::move(model));
	m_BoundingSphere2.Center = XMFLOAT3(3.0f, -4.3f, -7.0f);
	m_BoundingSphere2.Radius = 1.0f;
	m_Sphere2.SetWorldMatrix(XMMatrixTranslation(3.0f, -4.3f, -7.0f));

	// 球体3
	model.SetMesh(m_pd3dDevice.Get(), Geometry::CreateSphere(0.7f, 30, 30));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\floor.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Sphere3.SetModel(std::move(model));
	m_BoundingSphere3.Center = XMFLOAT3(-3.0f, -4.3f, -7.0f);
	m_BoundingSphere3.Radius = 1.0f;
	m_Sphere3.SetWorldMatrix(XMMatrixTranslation(-3.0f, -4.3f, -7.0f));


	// 地面
	model.SetMesh(m_pd3dDevice.Get(), Geometry::CreatePlane(XMFLOAT2(50.0f, 50.0f), XMFLOAT2(3.0f, 3.0f)));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f); 
	model.modelParts[0].material.reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\floor2.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Ground.SetModel(std::move(model));
	m_Ground.SetWorldMatrix(XMMatrixTranslation(0.0f, -5.0f, 0.0f));


	// 柱体1
	model.SetMesh(m_pd3dDevice.Get(),
		Geometry::CreateCylinder(0.5f, 2.0f));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\bricks.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Cylinder1.SetModel(std::move(model));
	m_Cylinder1.SetWorldMatrix(XMMatrixTranslation(0.0f, -3.99f, 0.0f));

	// 柱体2
	model.SetMesh(m_pd3dDevice.Get(),
		Geometry::CreateCylinder(0.5f, 2.0f));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\bricks.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Cylinder2.SetModel(std::move(model));
	m_Cylinder2.SetWorldMatrix(XMMatrixTranslation(5.0f, -3.99f, 3.0f));

	// 柱体3
	model.SetMesh(m_pd3dDevice.Get(),
		Geometry::CreateCylinder(0.5f, 2.0f));
	model.modelParts[0].material.ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	model.modelParts[0].material.diffuse = XMFLOAT4(0.8f, 0.8f, 0.8f, 1.0f);
	model.modelParts[0].material.specular = XMFLOAT4(0.2f, 0.2f, 0.2f, 16.0f);
	model.modelParts[0].material.reflect = XMFLOAT4();
	HR(CreateDDSTextureFromFile(m_pd3dDevice.Get(),
		L"Texture\\bricks.dds",
		nullptr,
		model.modelParts[0].texDiffuse.GetAddressOf()));
	m_Cylinder3.SetModel(std::move(model));
	m_Cylinder3.SetWorldMatrix(XMMatrixTranslation(-5.0f, -3.99f, 8.0f));



	// ******************
	// 初始化摄像机
	//
	auto camera = std::shared_ptr<FirstPersonCamera>(new FirstPersonCamera);
	m_pCamera = camera;
	camera->SetViewPort(0.0f, 0.0f, (float)m_ClientWidth, (float)m_ClientHeight);
	camera->SetFrustum(XM_PI / 3, AspectRatio(), 1.0f, 1000.0f);
	camera->LookTo(
		XMVectorSet(0.0f, 0.0f, -10.0f, 1.0f),
		XMVectorSet(0.0f, 0.0f, 1.0f, 1.0f),
		XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	// 初始化并更新观察矩阵、投影矩阵(摄像机将被固定)
	camera->UpdateViewMatrix();
	m_BasicEffect.SetViewMatrix(camera->GetViewXM());
	m_BasicEffect.SetProjMatrix(camera->GetProjXM());


	// ******************
	// 初始化不会变化的值
	//

	// 方向光
	DirectionalLight dirLight[4];
	dirLight[0].ambient = XMFLOAT4(0.15f, 0.15f, 0.15f, 1.0f);
	dirLight[0].diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	dirLight[0].specular = XMFLOAT4(0.1f, 0.1f, 0.1f, 1.0f);
	dirLight[0].direction = XMFLOAT3(-0.577f, -0.577f, 0.577f);
	dirLight[1] = dirLight[0];
	dirLight[1].direction = XMFLOAT3(0.577f, -0.577f, 0.577f);
	dirLight[2] = dirLight[0];
	dirLight[2].direction = XMFLOAT3(0.577f, -0.577f, -0.577f);
	dirLight[3] = dirLight[0];
	dirLight[3].direction = XMFLOAT3(-0.577f, -0.577f, -0.577f);
	for (int i = 0; i < 4; ++i)
		m_BasicEffect.SetDirLight(i, dirLight[i]);


	// ******************
	// 设置调试对象名
	//
	m_Cylinder1.SetDebugObjectName("Cylinder1");
	m_Ground.SetDebugObjectName("Ground");
	m_Sphere1.SetDebugObjectName("Sphere1");
	m_Sphere2.SetDebugObjectName("Sphere2");
	m_Sphere3.SetDebugObjectName("Sphere3");
	m_pDaylight->SetDebugObjectName("DayLight");
	m_pSunset->SetDebugObjectName("Sunset");
	m_pDesert->SetDebugObjectName("Desert");
	return true;
}

