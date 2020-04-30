#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "d3dApp.h"
#include "Camera.h"
#include "GameObject.h"
#include "SkyRender.h"
#include "ObjReader.h"
#include "Collision.h"
class GameApp : public D3DApp
{
public:
	// 摄像机模式
	enum class CameraMode { FirstPerson, ThirdPerson, Free };
	// 天空盒模式
	enum class SkyBoxMode { Daylight, Sunset, Desert };
	int cy1draw = 1;
	int cy2draw = 1;
	int cy3draw = 1;
	int sq1draw = 1;
	int sq2draw = 1;
	int sq3draw = 1;

public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

private:
	bool InitResource();
	
private:
	
	ComPtr<ID2D1SolidColorBrush> m_pColorBrush;				    // 单色笔刷
	ComPtr<IDWriteFont> m_pFont;								// 字体
	ComPtr<IDWriteTextFormat> m_pTextFormat;					// 文本格式

	GameObject m_Sphere1;										// 球
	GameObject m_Sphere2;
	GameObject m_Sphere3;
	DirectX::BoundingSphere m_BoundingSphere1;				    // 球1的包围盒
	DirectX::BoundingSphere m_BoundingSphere2;				    // 球2的包围盒
	DirectX::BoundingSphere m_BoundingSphere3;				    // 球3的包围盒

	GameObject m_Ground;										// 地面
	GameObject m_Cylinder1;									    // 圆柱
	GameObject m_Cylinder2;
	GameObject m_Cylinder3;
	BasicEffect m_BasicEffect;								    // 对象渲染特效管理
	
	SkyEffect m_SkyEffect;									    // 天空盒特效管理
	std::unique_ptr<SkyRender> m_pDaylight;					    // 天空盒(白天)
	std::unique_ptr<SkyRender> m_pSunset;						// 天空盒(日落)
	std::unique_ptr<SkyRender> m_pDesert;						// 天空盒(沙漠)
	SkyBoxMode m_SkyBoxMode;									// 天空盒模式

	std::wstring m_PickedObjStr;								//当前指向对象名
	std::wstring m_TouchObjStr;								//碰撞提示


	std::shared_ptr<Camera> m_pCamera;						    // 摄像机
	CameraMode m_CameraMode;									// 摄像机模式

	ObjReader m_ObjReader;									    // 模型读取对象
};


#endif