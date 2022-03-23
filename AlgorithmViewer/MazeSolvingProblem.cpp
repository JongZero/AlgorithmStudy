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
				myPos = { i, j };
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

	if (flowTime > 2 && !isEnd)
	{
		flowTime = 0;

		// 상, 하, 좌, 우 탐색
		POINT tdlr[4] = { {0, 0} };
		
		for (int i = 0; i < 4; i++)
		{
			POINT nowPos = myPos;

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

			if (nowPos.x < 0 || nowPos.y < 0)
			{
				continue;
			}

			bool check = false;
			for (int j = 0; j < m_checkVec.size(); j++)
			{
				if (m_checkVec[j].x == nowPos.x && m_checkVec[j].y == nowPos.y)
				{
					check = true;
					break;
				}
			}

			if (check || map[nowPos.x][nowPos.y] == X)
				continue;

			if (map[nowPos.x][nowPos.y] == E)
			{
				isEnd = true;
			}

			m_stack.push(nowPos);
		}

		if (!m_stack.empty())
		{
			m_checkVec.push_back(myPos);
			myPos = m_stack.top();
			m_stack.pop();
		}
	}
}

void MazeSolvingProblem::Draw(D2DRenderer* d2dRenderer)
{
	POINT nowPos = startPos;
	int size = offset * 0.8f;

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			ColorF color(ColorF::White);

			if (map[i][j] == X)
			{
				color = ColorF(ColorF::Red);
			}

			if (i == myPos.x && j == myPos.y)
			{
				color = ColorF(ColorF::Green);
				d2dRenderer->DrawFillEllipse(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, color);
			}
			else
			{
				d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, color);
			}

			// 왔던 길 표시
			for (int k = 0; k < m_checkVec.size(); k++)
			{
				if (i == m_checkVec[k].x && j == m_checkVec[k].y)
				{
					d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
					break;
				}
			}

			d2dRenderer->DrawText(nowPos.x, nowPos.y, ColorF(ColorF::Gray), L"%d, %d", i, j);
			nowPos.x += offset;
		}

		nowPos.x = startPos.x;
		nowPos.y += offset;
	}

	d2dRenderer->DrawTextW(offset * MAP_SIZE - 100, 0, L"Now Pos : %d, %d", myPos.x, myPos.y);
}
