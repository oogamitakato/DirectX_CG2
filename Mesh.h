#pragma once
#include <d3d12.h>
#include <DirectXTex.h>
#include "Mesh.h"
using namespace DirectX;

class Mesh
{
public:
	//定数バッファ用データ構造体(マテリアル)
	struct ConstBufferDateMaterial {
		XMFLOAT4 color; //色(RGBA)
	};

	//定数バッファ用データ構造体
	struct ConstBufferDateTransform {
		XMMATRIX mat;//3D変換行列
	};

	//頂点データ構造体
	struct Vertex
	{
		XMFLOAT3 pos;//xyz座標
		//XMFLOAT2 uv;//uv座標
	};

	//メンバ変数
	HRESULT result;
	ID3D12Device* device;
	Vertex vertices[4] = {
		//x      y      z     
		{{-0.1f, -0.1f, 0.0f}},//左下
		{{-0.1f, +0.1f, 0.0f}},//左上
		{{+0.1f, -0.1f, 0.0f}},//右下
		{{+0.1f, +0.1f, 0.0f}},//右上
	};

	//GPU上のバッファに対応した仮想メモリ(メインメモリ上)を取得
	Vertex* vertMap = nullptr;
	//パイプラインステートの生成
	ID3D12PipelineState* pipelineState;
	//ルートシグネチャ
	ID3D12RootSignature* rootSignature;
	//頂点バッファビューの生成
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//定数バッファのマッピング
	ConstBufferDateMaterial* constMapMaterial;
	ID3D12Resource* constBuffMaterial;
	ID3D12Resource* constBuffTransform = nullptr;
	ConstBufferDateTransform* constMapTransform = nullptr;
	
	//インデックスバッファビューの生成
	D3D12_INDEX_BUFFER_VIEW ibView{};
	//設定を元にSRV用デスクリプタヒープを生成
	ID3D12DescriptorHeap* srvHeap;

	//メンバ関数
	Mesh(ID3D12Device* device);
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);
};