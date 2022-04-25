#include <iostream>
#include <vector>
#include <stack>

struct Bus
{
	int startCityNum = 0;	// 출발 도시 번호
	int endCityNum = 0;		// 도착 도시 번호
	int cost = 0;			// 버스의 비용
	bool isUsed = false;	// 사용되었는지?
};

int n = 0;
int m = 0;

std::vector<Bus> busVec(m);

int problemStart = 0;
int problemEnd = 0;

unsigned long long resultMin = 100000 * 100000;

void Func(int start, int cost)
{
	if (start == problemEnd)
	{
		if (cost < resultMin)
		{
			resultMin = cost;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			// 이전에 사용되지 않았고, 출발 지점의 버스라면
			if (busVec[i].isUsed == false && busVec[i].startCityNum == start)
			{
				// 사용하고
				busVec[i].isUsed = true;

				cost += busVec[i].cost;

				// 출발지점 변경 (도착지점으로)
				Func(busVec[i].endCityNum, cost);

				// 리셋
				busVec[i].isUsed = false;

				cost -= busVec[i].cost;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;
	std::cin >> m;

	busVec.resize(m);

	for (int i = 0; i < m; i++)
	{
		std::cin >> busVec[i].startCityNum >> busVec[i].endCityNum >> busVec[i].cost;
	}

	// 구해야하는 시작부터 끝
	std::cin >> problemStart >> problemEnd;

	// 전부 돌기
	//Func(problemStart, 0);

	// 전부 돌지않고 효율 구하기
	/*
	int result = 0;
	int start = problemStart;
	std::stack<Bus> busStack;	// 이용할 버스들
	int tempIndex = 0;
	while (start < problemEnd)
	{
		int tempMax = -100000;
		for (int j = tempIndex; j < m; j++)
		{
			if (start == busVec[j].startCityNum)
			{
				// 가는 거리와 비용을 비교
				int dist = busVec[j].endCityNum - busVec[j].startCityNum;

				int temp = dist - busVec[j].cost;

				if (temp > tempMax)
				{
					tempMax = temp;
					tempIndex = j;
				}
			}
			else if (start < busVec[j].startCityNum)
				break;
		}

		Bus _bus = busVec[tempIndex];
		result += _bus.cost;
		start = _bus.endCityNum;
	}

	std::cout << result;
	*/



	return 0;
}