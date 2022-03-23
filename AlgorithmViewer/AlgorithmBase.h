#pragma once
#include <windows.h>
#include "GraphicsEngine_D2D.h"

// �˰��� ����� ���̽� Ŭ����
__interface AlgorithmBase
{
public:
	void Update(float dTime) abstract;
	void Draw(D2DRenderer* d2dRenderer) abstract;
};