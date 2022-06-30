#pragma once
#include <d3d12.h>
#include <DirectXTex.h>
#include "Mesh.h"
using namespace DirectX;

class Mesh
{
public:
	//�萔�o�b�t�@�p�f�[�^�\����(�}�e���A��)
	struct ConstBufferDateMaterial {
		XMFLOAT4 color; //�F(RGBA)
	};

	//�萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferDateTransform {
		XMMATRIX mat;//3D�ϊ��s��
	};

	//���_�f�[�^�\����
	struct Vertex
	{
		XMFLOAT3 pos;//xyz���W
		//XMFLOAT2 uv;//uv���W
	};

	//�����o�ϐ�
	HRESULT result;
	//ID3D12Device* device;
	Vertex vertices[4] = {
		//x      y      z     
		{{-0.1f, -0.0f, 0.0f}},//����
		{{-0.1f, +0.0f, 0.0f}},//����
		{{+0.1f, -0.0f, 0.0f}},//�E��
		{{+0.1f, +0.0f, 0.0f}},//�E��
	};

	//GPU��̃o�b�t�@�ɑΉ��������z������(���C����������)���擾
	Vertex* vertMap = nullptr;
	//�p�C�v���C���X�e�[�g�̐���
	ID3D12PipelineState* pipelineState;
	//���[�g�V�O�l�`��
	ID3D12RootSignature* rootSignature;
	//���_�o�b�t�@�r���[�̐���
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//�萔�o�b�t�@�̃}�b�s���O
	ConstBufferDateMaterial* constMapMaterial;
	ID3D12Resource* constBuffMaterial;
	ID3D12Resource* constBuffTransform = nullptr;
	ConstBufferDateTransform* constMapTransform = nullptr;
	
	//�C���f�b�N�X�o�b�t�@�r���[�̐���
	D3D12_INDEX_BUFFER_VIEW ibView{};
	//�ݒ������SRV�p�f�X�N���v�^�q�[�v�𐶐�
	ID3D12DescriptorHeap* srvHeap;

	//�����o�֐�
	Mesh(ID3D12Device* device);
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);
};