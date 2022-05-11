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
		bool isMatchCount5 = true;	// 승리 + 무승부 + 패배 경기 수가 5인지
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

		// win, draw, lose마다 최대 수가 정해져있음
		if (winCount > TotalMatchCount || loseCount > TotalMatchCount || drawCount > TotalMatchCount * 2)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// 한 국가 당 경기 수는 5가 되야함
		if (!isMatchCount5)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// 승 == 패?
		if (winCount != loseCount)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// 무의 수 짝수?
		if (drawCount % 2 != 0)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// 총 경기수 15경기?
		if (winCount + (drawCount / 2) != TotalMatchCount)
		{
			resultVec.emplace_back(0);
			continue;
		}

		// 한 국가의 무의 수가 나머지 국가들의 무의 수와 매칭이 되는가?
		bool isMatchingDrawCount = true;
		for (int j = 0; j < 6; j++)
		{
			Country c = countryVec[j];
			int nowCDrawCount = get<1>(c);

			// 무승부를 했다면
			if (nowCDrawCount > 0)
			{
				// 다른 국가들의 무승부 수와 비교
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

	// 6개의 나라가 경기를 해서, 가능한 경우의 수를 체크
	


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

			// 이기는 경우
			Func(count + 1, eType::Win, i);
			get<0>(countryVec[i])++;

			// 비기는 경우
			Func(count + 1, eType::Draw, i);
			get<1>(countryVec[i])++;

			// 지는 경우
			Func(count + 1, eType::Lose, i);
			get<2>(countryVec[i])++;

			isVisitedVec[i] = false;
		}
	}
}