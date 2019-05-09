#pragma once
#include "pch.h"
#include "Content/ShaderStructures.h"

using namespace DirectX;
using namespace Microsoft::WRL;

class Model {

public:

	Model();

	void InitGraphics(ComPtr<ID3D11Device> dev,VERTEX vertices[], UINT vertArraySize);
	void InitIndexedGraphics(ComPtr<ID3D11Device> dev, VERTEX vertices[], UINT vertArraySize, short indices[], UINT indArraySize);
	void DrawGraphics(ComPtr<ID3D11DeviceContext1> devcon, ComPtr<ID3D11Buffer> constantbuffer, D3D11_PRIMITIVE_TOPOLOGY topology, XMMATRIX matFinal, UINT vertArraySize);
	void DrawIndexedGraphics(ComPtr<ID3D11DeviceContext1> devcon, ComPtr<ID3D11Buffer> constantbuffer, D3D11_PRIMITIVE_TOPOLOGY topology, XMMATRIX matFinal, UINT indArraySize);

	//Methods for updating position, rotation, and scale of model
	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	void UpdateWorldMatrix();
	XMMATRIX GetWorldMatrix();

	XMVECTOR position; //define x, y, and z position in world space
	XMVECTOR rotation; //define rotation in x,y, and z axis.
	XMVECTOR scale; //define scale in x, y, and z direction

	XMMATRIX matTranslate; //translation matrix
	XMMATRIX matRotate; // rotation matrix
	XMMATRIX matScale; // scaling matrix

	XMMATRIX matWorld; //world matrix

private:

	ComPtr<ID3D11Buffer> vertexbuffer; //vertex buffer
	ComPtr<ID3D11Buffer> indexbuffer; //index buffer

};