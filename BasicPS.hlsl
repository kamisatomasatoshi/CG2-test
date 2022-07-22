#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);  	// 0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp : register(s0);      	// 0�ԃX���b�g�ɐݒ肳�ꂽ�T���v���[

float4 main(VSOutput input) : SV_TARGET{
    float4 texcolor = float4(tex.Sample(smp, input.uv)) * color;
    /*return float4(1,1,1,1);*/
    /*return float4(input.normal,1);*/
    //float3 light = normalize(float3(1,-1,1));
    //float brightness = dot(-light, input.normal);
    //return float4 (brightness, brightness, brightness, 1);
    float3 light = normalize(float3(1,1,1));
    float diffuse = saturate(dot(-light, input.normal));
    float brightness = diffuse + 0.3f;
    //return float4(brightness, brightness, brightness, 1);
    return float4 (texcolor.rgb * brightness, texcolor.a) * color;
    //return color;
    //return float4(color);
}
