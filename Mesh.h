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
		XMFLOAT2 uv;//uv座標
	};

	//メンバ変数
	HRESULT result;
	ID3D12Device* device;
	//頂点データ
	Vertex vertices[24] = {
		//x      y      z      u    v
		//前
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//左下
		{{-5.0f,  5.0f, -5.0f},{0.0f,0.0f}},//左上
		{{ 5.0f, -5.0f, -5.0f},{1.0f,1.0f}},//右上
		{{ 5.0f,  5.0f, -5.0f},{1.0f,0.0f}},//右上
		//後
		{{-5.0f, -5.0f, 5.0f},{0.0f,1.0f}},//左下
		{{-5.0f,  5.0f, 5.0f},{0.0f,0.0f}},//左上
		{{ 5.0f, -5.0f, 5.0f},{1.0f,1.0f}},//右上
		{{ 5.0f,  5.0f, 5.0f},{1.0f,0.0f}},//右上
		//左
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//左下
		{{-5.0f, -5.0f,  5.0f},{0.0f,0.0f}},//左上
		{{-5.0f,  5.0f, -5.0f},{1.0f,1.0f}},//右上
		{{-5.0f,  5.0f,  5.0f},{1.0f,0.0f}},//右上
		//右
		{{ 5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//左下
		{{ 5.0f, -5.0f,  5.0f},{0.0f,0.0f}},//左上
		{{ 5.0f,  5.0f, -5.0f},{1.0f,1.0f}},//右上
		{{ 5.0f,  5.0f,  5.0f},{1.0f,0.0f}},//右上
		//下
		{{-5.0f, -5.0f, -5.0f},{0.0f,1.0f}},//左下
		{{05.0f, -5.0f, -5.0f},{0.0f,0.0f}},//左上
		{{-5.0f, -5.0f,  5.0f},{1.0f,1.0f}},//右上
		{{05.0f, -5.0f,  5.0f},{1.0f,0.0f}},//右上
		//上
		{{-5.0f,  5.0f, -5.0f},{0.0f,1.0f}},//左下
		{{05.0f,  5.0f, -5.0f},{0.0f,0.0f}},//左上
		{{-5.0f,  5.0f,  5.0f},{1.0f,1.0f}},//右上
		{{05.0f,  5.0f,  5.0f},{1.0f,0.0f}},//右上
	};

	//インデックスデータ
	unsigned short indices[36] = {
		//前
		0, 1, 2,//三角形一つ目
		1, 2, 3,//三角形二つ目
		//後
		4, 5, 6,//三角形三つ目
		5, 6, 7,//三角形四つ目
		//左
		8,  9, 10,
		9, 10, 11,
		//右
		12, 13, 14,
		13, 14, 15,
		//下
		16, 17, 18,
		17, 18, 19,
		//上
		20, 21, 22,
		21, 22, 23,
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

	//射影変換行列
	XMMATRIX matProjection;

	//ビュー変換行列
	XMMATRIX matView;
	XMFLOAT3 eye = { 0, 0, -100 };		//視点座標
	XMFLOAT3 target = { 0, 0, 0 };	//注視点座標
	XMFLOAT3 up = { 0, 1, 0 };		//上方向ベクトル
	float angle = 0.0f;//カメラの回転角

	//ワールド変換行列
	XMMATRIX matWorld;

	XMMATRIX matScale;
	XMMATRIX matRot;
	XMMATRIX matTrans;

	//スケーリング倍率
	XMFLOAT3 scale = { 1.0f,1.0f,1.0f };
	//回転角
	XMFLOAT3 rotation = { 0.0f,0.0f,0.0f };
	//座標
	XMFLOAT3 position = { 0.0f,0.0f,0.0f };

	//メンバ関数
	Mesh(ID3D12Device* device);
	void Update(IDirectInputDevice8* keyboard);
	void Draw(ID3D12GraphicsCommandList* commandList);
};