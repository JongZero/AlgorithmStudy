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
	int offset = 100;
	POINT startPos = { 20, 20 };
	std::stack<POINT> m_stack;

	POINT myPos = { 0, 0 };		// 내 위치(map의 인덱스)

	std::vector<POINT> m_checkVec;		// 내가 지나 왔던 곳
	bool isEnd = false;

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