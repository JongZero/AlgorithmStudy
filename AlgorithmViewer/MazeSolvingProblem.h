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

	POINT myPos = { 0, 0 };		// �� ��ġ(map�� �ε���)

	std::vector<POINT> m_checkVec;		// ���� ���� �Դ� ��
	bool isEnd = false;

	// 4����
	enum class eDir
	{
		Top,
		Down,
		Left,
		Right
	};

	enum eMapAttr
	{
		O,	// �� �� ����
		X,	// ������ ��
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