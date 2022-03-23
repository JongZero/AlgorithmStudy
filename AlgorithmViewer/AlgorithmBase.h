#pragma once
#include <windows.h>
#include "GraphicsEngine_D2D.h"

// 알고리즘 뷰어의 베이스 클래스
__interface AlgorithmBase
{
public:
	void Update(float dTime) abstract;
	void Draw(D2DRenderer* d2dRenderer) abstract;
};