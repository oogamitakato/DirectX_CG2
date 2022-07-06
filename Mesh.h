#pragma once
#include <d3d12.h>
#include <DirectXTex.h>
#include <dinput.h>
#include "Mesh.h"
#include "Global.h"

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
		XMFLOAT2 uv;//uv���W
	};

	//�����o�ϐ�
	HRESULT result;
	ID3D12Device* device;
	//���_�f�[�^
	Vertex vertices[24] = {
		//x      y      z      u    v
		//�O
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//����
		{{-5.0f,  5.0f, -5.0f},{0.0f,0.0f}},//����
		{{ 5.0f, -5.0f, -5.0f},{1.0f,1.0f}},//�E��
		{{ 5.0f,  5.0f, -5.0f},{1.0f,0.0f}},//�E��
		//��
		{{-5.0f, -5.0f, 5.0f},{0.0f,1.0f}},//����
		{{-5.0f,  5.0f, 5.0f},{0.0f,0.0f}},//����
		{{ 5.0f, -5.0f, 5.0f},{1.0f,1.0f}},//�E��
		{{ 5.0f,  5.0f, 5.0f},{1.0f,0.0f}},//�E��
		//��
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//����
		{{-5.0f, -5.0f,  5.0f},{0.0f,0.0f}},//����
		{{-5.0f,  5.0f, -5.0f},{1.0f,1.0f}},//�E��
		{{-5.0f,  5.0f,  5.0f},{1.0f,0.0f}},//�E��
		//�E
		{{ 5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//����
		{{ 5.0f, -5.0f,  5.0f},{0.0f,0.0f}},//����
		{{ 5.0f,  5.0f, -5.0f},{1.0f,1.0f}},//�E��
		{{ 5.0f,  5.0f,  5.0f},{1.0f,0.0f}},//�E��
		//��
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//����
		{{05.0f, -5.0f, -5.0f},{0.0f,0.0f}},//����
		{{-5.0f, -5.0f,  5.0f},{1.0f,1.0f}},//�E��
		{{05.0f, -5.0f,  5.0f},{1.0f,0.0f}},//�E��
		//��
		{{-5.0f,  5.0f, -5.0f},{0.0f,1.0f}},//����
		{{05.0f,  5.0f, -5.0f},{0.0f,0.0f}},//����
		{{-5.0f,  5.0f,  5.0f},{1.0f,1.0f}},//�E��
		{{05.0f,  5.0f,  5.0f},{1.0f,0.0f}},//�E��
	};

	//�C���f�b�N�X�f�[�^
	unsigned short indices[36] = {
		//�O
		0, 1, 2,//�O�p�`���
		1, 2, 3,//�O�p�`���
		//��
		4, 5, 6,//�O�p�`�O��
		5, 6, 7,//�O�p�`�l��
		//��
		8,  9, 10,
		9, 10, 11,
		//�E
		12, 13, 14,
		13, 14, 15,
		//��
		16, 17, 18,
		17, 18, 19,
		//��
		20, 21, 22,
		21, 22, 23,
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

	//�ˉe�ϊ��s��
	XMMATRIX matProjection;

	//�r���[�ϊ��s��
	XMMATRIX matView;
	XMFLOAT3 eye = { 0, 0, -100 };		//���_���W
	XMFLOAT3 target = { 0, 0, 0 };	//�����_���W
	XMFLOAT3 up = { 0, 1, 0 };		//������x�N�g��
	float angle = 0.0f;//�J�����̉�]�p

	//���[���h�ϊ��s��
	XMMATRIX matWorld;

	XMMATRIX matScale;
	XMMATRIX matRot;
	XMMATRIX matTrans;

	//�X�P�[�����O�{��
	XMFLOAT3 scale = { 1.0f,1.0f,1.0f };
	//��]�p
	XMFLOAT3 rotation = { 0.0f,0.0f,0.0f };
	//���W
	XMFLOAT3 position = { 0.0f,0.0f,0.0f };

	//�����o�֐�
	Mesh(ID3D12Device* device);
	void Update(IDirectInputDevice8* keyboard);
	void Draw(ID3D12GraphicsCommandList* commandList);
};