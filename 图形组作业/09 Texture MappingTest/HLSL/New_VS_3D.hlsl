#include "Basic.hlsli"

// ¶¥µã×ÅÉ«Æ÷(3D)
VertexPosHWNormalTex New_VS_3D(VertexPosNormalTex vIn)
{
    VertexPosHWNormalTex vOut;
    matrix viewProj = mul(g_View, g_Proj);
    float4 posW = mul(float4(vIn.PosL, 1.0f), g_World);

    vOut.PosH = mul(posW, viewProj);
    vOut.PosW = posW.xyz;
    vOut.NormalW = mul(vIn.NormalL, (float3x3) g_WorldInvTranspose);
    vIn.Tex -= 0.5f;
    vOut.Tex = mul(g_texMat, float4(vIn.Tex, 0.0f, 0.0f));
    vOut.Tex += 0.5f;
    return vOut;
}