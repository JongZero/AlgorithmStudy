#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> Country;

const int TotalMatchCount = 15;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	/*
	vector<int> resultVec;
	for (int i = 0; i < 4; i++)
	{
		vector<Country> countryVec;

		int winCount = 0;
		int drawCount = 0;
		int loseCount = 0;
		bool isMatchCount5 = true;	// �¸� + ���º� + �й� ��� ���� 5����
		for (int j = 0; j < 6; j++)
		{
			int win, draw, lose;
			cin >> win >> draw >> lose;

			if (win + draw + lose != 5)
				isMatchCount5 = false;

			winCount += win;
			drawCount += draw;
			loseCount += lose;

			Country c = make_tuple(win, draw, lose);
			countryVec.push_back(c);
		}

		// win, draw, lose���� �ִ� ���� ����������
		if (winCount > TotalMatchCount || loseCount > TotalMatchCount || drawCount > TotalMatchCount * 2)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// �� ���� �� ��� ���� 5�� �Ǿ���
		if (!isMatchCount5)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// �� == ��?
		if (winCount != loseCount)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// ���� �� ¦��?
		if (drawCount % 2 != 0)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// �� ���� 15���?
		if (winCount + (drawCount / 2) != TotalMatchCount)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// �� ������ ���� ���� ������ �������� ���� ���� ��Ī�� �Ǵ°�?
		bool isMatchingDrawCount = true;
		for (int j = 0; j < 6; j++)
		{
			Country c = countryVec[j];
			int nowCDrawCount = get<1>(c);

			// ���ºθ� �ߴٸ�
			if (nowCDrawCount > 0)
			{
				// �ٸ� �������� ���º� ���� ��
				int tempDrawCount = 0;
				for (int k = 0; k < 6; k++)
				{
					if (k == j)
						continue;

					tempDrawCount += get<1>(countryVec[k]);

					if (tempDrawCount >= nowCDrawCount)
						break;
				}

				if (tempDrawCount < nowCDrawCount)
				{
					isMatchingDrawCount = false;
					break;
				}
			}
		}

		if (!isMatchingDrawCount)
		{
			resultVec.emplace_back(0);
			continue;
		}

		resultVec.emplace_back(1);
	}

	for (int i = 0; i < 4; i++)
	{
		cout << resultVec[i] << ' ';
	}
	*/

	// 6���� ���� ��⸦ �ؼ�, ������ ����� ���� üũ
	


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{

		}
	}

	return 0;
}

enum class eType
{
	Win,
	Draw,
	Lose
};

vector<Country> countryVec(6);
vector<bool> isVisitedVec(6);

void Func(int count, eType type, int countryNum)
{
	if (count == TotalMatchCount)
	{

	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (isVisitedVec[i] == true)
				continue;

			isVisitedVec[i] = true;

			// �̱�� ���
			Func(count + 1, eType::Win, i);
			get<0>(countryVec[i])++;

			// ���� ���
			Func(count + 1, eType::Draw, i);
			get<1>(countryVec[i])++;

			// ���� ���
			Func(count + 1, eType::Lose, i);
			get<2>(countryVec[i])++;

			isVisitedVec[i] = false;
		}
	}
}