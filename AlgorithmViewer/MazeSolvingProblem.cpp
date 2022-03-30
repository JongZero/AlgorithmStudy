#include "MazeSolvingProblem.h"

MazeSolvingProblem::MazeSolvingProblem()
{
	// 내 위치를 찾는다.
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (map[i][j] == S)
			{
				m_MyPos = { i, j };
				break;
			}
		}
	}
}

MazeSolvingProblem::~MazeSolvingProblem()
{

}

void MazeSolvingProblem::Update(float dTime)
{
	// 과정을 보기 위해 1초에 한 번씩 움직이도록한다.
	static float flowTime = 0;
	flowTime += dTime;

	if (flowTime > 1.2f && !m_IsEnd)
	{
		flowTime = 0;

		// 스택에 원소가 있다면 (이동가능한 곳이 있다면)
		// 내 위치를 다음 위치(top)로 변경
		if (!m_MovableStack.empty())
		{
			m_CheckVec.push_back(m_MyPos);
			m_MyPos = m_MovableStack.top();
			m_MovableStack.pop();
			m_ForDesStack.pop();
		}

		// 도착 지점인지
		if (map[m_MyPos.x][m_MyPos.y] == E)
		{
			m_IsEnd = true;
		}
		
		// 상, 하, 좌, 우 탐색
		POINT tdlr[4] = { {0, 0} };
		
		for (int i = 0; i < 4; i++)
		{
			POINT nowPos = m_MyPos;

			switch (i)
			{
			case static_cast<int>(eDir::Top):
				nowPos.y--;
				break;
			case static_cast<int>(eDir::Down):
				nowPos.y++;
				break;
			case static_cast<int>(eDir::Left):
				nowPos.x--;
				break;
			case static_cast<int>(eDir::Right):
				nowPos.x++;
				break;
			}

			// 배열에서 벗어난 인덱스일 경우
			if (nowPos.x < 0 || nowPos.y < 0)
			{
				continue;
			}

			// 이전에 갔던 곳인지 체크한다.
			bool check = false;
			for (int j = 0; j < m_CheckVec.size(); j++)
			{
				if (m_CheckVec[j].x == nowPos.x && m_CheckVec[j].y == nowPos.y)
				{
					check = true;
					break;
				}
			}

			// 이전에 갔던 곳인지 또는 벽인지
			if (check || map[nowPos.x][nowPos.y] == X)
				continue;

			m_MovableStack.push(nowPos);
			m_ForDesStack.push(nowPos);
		}
	}
}

void MazeSolvingProblem::Draw(D2DRenderer* d2dRenderer)
{
	POINT nowPos = m_StartPos;
	int size = m_Offset * 0.8f;

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			ColorF color(ColorF::White);

			if (map[i][j] == X)
			{
				color = ColorF(ColorF::Red);
			}

			if (i == m_MyPos.x && j == m_MyPos.y)
			{
				color = ColorF(ColorF::Green);
				d2dRenderer->DrawFillEllipse(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, color);
			}
			else
			{
				d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, color);
			}

			// 왔던 길 표시
			for (int k = 0; k < m_CheckVec.size(); k++)
			{
				if (i == m_CheckVec[k].x && j == m_CheckVec[k].y)
				{
					d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
					break;
				}
			}

			d2dRenderer->DrawText(nowPos.x, nowPos.y, ColorF(ColorF::Black), L"%d, %d", i, j);
			nowPos.x += m_Offset;
		}

		nowPos.x = m_StartPos.x;
		nowPos.y += m_Offset;
	}

	d2dRenderer->DrawTextW(m_Offset * MAP_SIZE - 100, 0, L"Now Pos : %d, %d", m_MyPos.x, m_MyPos.y);

	// 오른쪽 끝 한 칸 옆에 설명 표시
	POINT desPos = { m_Offset * (MAP_SIZE + 1), m_StartPos.y };
	nowPos.x = desPos.x;
	nowPos.y = desPos.y;

	// Player
	d2dRenderer->DrawFillEllipse(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : 현재 위치");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;
	// 왔던 곳
	d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : 왔던 길");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;
	// 벽
	d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Red));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : 벽");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;

	// 현재 스택 상황
	// 둘러싸는 사각형
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L"[ Stack ]");
	nowPos.y += m_Offset / 4;
	d2dRenderer->DrawRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size * 3, ColorF(ColorF::White));
	nowPos.y = nowPos.y + size * 2 + size / 2;
	
	std::stack<POINT> _tempStack(m_ForDesStack);
	std::stack<POINT> _tempStack2;		// 스택을 복사해서 그대로 출력하면 반대로 나오기 때문에, 다시 반대로 뒤집어준다.
	while (!_tempStack.empty())
	{
		POINT top = _tempStack.top();
		_tempStack2.push(top);
		_tempStack.pop();
	}

	while (!_tempStack2.empty())
	{
		POINT top = _tempStack2.top();
		d2dRenderer->DrawTextW(nowPos.x + 15, nowPos.y, L"( %d, %d )", top.x, top.y);
		nowPos.y -= m_Offset / 4;
		_tempStack2.pop();
	}

	if (m_IsEnd)
	{
		d2dRenderer->DrawText(190, 250, 50, L" 미로 탈출! ");
	}
}
