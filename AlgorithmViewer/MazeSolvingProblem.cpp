#include "MazeSolvingProblem.h"

MazeSolvingProblem::MazeSolvingProblem()
{
	// �� ��ġ�� ã�´�.
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
	// ������ ���� ���� 1�ʿ� �� ���� �����̵����Ѵ�.
	static float flowTime = 0;
	flowTime += dTime;

	if (flowTime > 1.2f && !m_IsEnd)
	{
		flowTime = 0;

		// ���ÿ� ���Ұ� �ִٸ� (�̵������� ���� �ִٸ�)
		// �� ��ġ�� ���� ��ġ(top)�� ����
		if (!m_MovableStack.empty())
		{
			m_CheckVec.push_back(m_MyPos);
			m_MyPos = m_MovableStack.top();
			m_MovableStack.pop();
			m_ForDesStack.pop();
		}

		// ���� ��������
		if (map[m_MyPos.x][m_MyPos.y] == E)
		{
			m_IsEnd = true;
		}
		
		// ��, ��, ��, �� Ž��
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

			// �迭���� ��� �ε����� ���
			if (nowPos.x < 0 || nowPos.y < 0)
			{
				continue;
			}

			// ������ ���� ������ üũ�Ѵ�.
			bool check = false;
			for (int j = 0; j < m_CheckVec.size(); j++)
			{
				if (m_CheckVec[j].x == nowPos.x && m_CheckVec[j].y == nowPos.y)
				{
					check = true;
					break;
				}
			}

			// ������ ���� ������ �Ǵ� ������
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

			// �Դ� �� ǥ��
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

	// ������ �� �� ĭ ���� ���� ǥ��
	POINT desPos = { m_Offset * (MAP_SIZE + 1), m_StartPos.y };
	nowPos.x = desPos.x;
	nowPos.y = desPos.y;

	// Player
	d2dRenderer->DrawFillEllipse(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : ���� ��ġ");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;
	// �Դ� ��
	d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Green));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : �Դ� ��");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;
	// ��
	d2dRenderer->DrawFillRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size, ColorF(ColorF::Red));
	nowPos.x += m_Offset;
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L" : ��");
	nowPos.y += m_Offset;
	nowPos.x = desPos.x;

	// ���� ���� ��Ȳ
	// �ѷ��δ� �簢��
	d2dRenderer->DrawTextW(nowPos.x, nowPos.y, L"[ Stack ]");
	nowPos.y += m_Offset / 4;
	d2dRenderer->DrawRectangle(nowPos.x, nowPos.y, nowPos.x + size, nowPos.y + size * 3, ColorF(ColorF::White));
	nowPos.y = nowPos.y + size * 2 + size / 2;
	
	std::stack<POINT> _tempStack(m_ForDesStack);
	std::stack<POINT> _tempStack2;		// ������ �����ؼ� �״�� ����ϸ� �ݴ�� ������ ������, �ٽ� �ݴ�� �������ش�.
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
		d2dRenderer->DrawText(190, 250, 50, L" �̷� Ż��! ");
	}
}
