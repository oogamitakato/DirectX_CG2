#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);	//0�ԃX���b�g�Ɏw�肳�ꂽ�e�N�X�`��
SamplerState smp : register(s0);		//0�ԃX���b�g�Ɏw�肳�ꂽ�T���v���[

float4 main(VSOutput input) : SV_TARGET
{
	//return float4(tex.Sample(smp, input.uv) * color);	//�摜
	return float4(input.uv,1,1) * color;	//�O���f�[�V����
	//return float4(input.normal,1);	//�V�F�[�f�B���O����
	//return color;	//color�����̂܂�
}
