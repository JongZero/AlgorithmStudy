#pragma once
#include "AlgorithmBase.h"
#include <stack>
#include <vector>

#define MAP_SIZE 6

class MazeSolvingProblem : public AlgorithmBase
{
public:
	MazeSolvingProblem();
	~MazeSolvingProblem();

private:
	int m_Offset = 100;
	POINT m_StartPos = { 20, 20 };
	std::stack<POINT> m_MovableStack;
	std::stack<POINT> m_ForDesStack;		// m_Stack의 상황을 보여주기 위한 스택
	bool m_IsDrawTempStack;				// 스택의 상황을 표시했는지?

	POINT m_MyPos = { 0, 0 };			// 내 위치(map의 인덱스)

	std::vector<POINT> m_CheckVec;		// 내가 지나 왔던 곳
	bool m_IsEnd = false;

	// 4방향
	enum class eDir
	{
		Top,
		Down,
		Left,
		Right
	};

	enum eMapAttr
	{
		O,	// 갈 수 있음
		X,	// 못가는 곳
		S,	// Start
		E,	// End
	};

	int map[MAP_SIZE][MAP_SIZE] = 
	{{ X, X, X, X, X, X },
	{ S, O, X, O, O, X },
	{ X, O, O, O, X, X },
	{ X, O, X, O, X, X },
	{ X, O, X, O, O, E },
	{ X, X, X, X, X, X }};

public:
	void Update(float dTime) override;
	void Draw(D2DRenderer* d2dRenderer) override;
};