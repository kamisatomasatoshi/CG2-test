#pragma once
#define DIRECTINPUT_VERSION 0x0800 //DirectInputのバージョン指定
#include<dinput.h>
#include<d3dcompiler.h>
#pragma comment(lib,"d3dcompiler.lib")
#include<Windows.h>
#include <tchar.h>
#include<iostream>
#include<d3d12.h>
#include<dxgi1_6.h>
#include<cassert>
#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include <vector>
#include <string>
#include<DirectXMath.h>

using namespace DirectX;
using namespace std;

class Mesh {

public:
	void Initialize(ID3D12Device* device);

	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	HRESULT result_;

	// ウィンドウ横幅
	const int window_width = 1280;
	// ウィンドウ縦幅
	const int window_height = 720;

	HRESULT result;

	// 頂点データ
	XMFLOAT3 vertices[3] = {
	{ -0.5f, -0.5f, +1.0f }, // 左下
	{ -0.5f, +0.5f, 0.0f }, // 左上
	{ +0.5f, -0.5f, 0.0f }, // 右下
	};

	//πプランステートの生成
	ID3D12PipelineState* pipelineStage = nullptr;
	// ルートシグネチャ
	ID3D12RootSignature* rootSignature;

	// 頂点バッファビューの作成
	D3D12_VERTEX_BUFFER_VIEW vbView{};

};