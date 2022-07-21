#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);	//0�ԃX���b�g�Ɏw�肳�ꂽ�e�N�X�`��
SamplerState smp : register(s0);		//0�ԃX���b�g�Ɏw�肳�ꂽ�T���v���[

float4 main(VSOutput input) : SV_TARGET
{
	float3 light = normalize(float3(1,-1,1));	//�E���������̃��C�g
	float diffuse = saturate(dot(-light, input.normal));	//diffuse��[0,1]�͈̔͂�Clamp����
	float brightness = diffuse + 0.3f;	//�A���r�G���g����0.3�Ƃ��Čv�Z
	float4 texcolor = float4(tex.Sample(smp, input.uv));

	return float4(texcolor.rgb * brightness, texcolor.a);	//�摜(�e�t��)
	//return float4(brightness, brightness, brightness, 1) * color;	//�P�x��RGB�ɑ�����ďo��
	//return float4(tex.Sample(smp, input.uv) * color);	//�摜
	//return float4(input.uv,1,1) * color;	//�O���f�[�V����
	//return color;	//color�����̂܂�
}
