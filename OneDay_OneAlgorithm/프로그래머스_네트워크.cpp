#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int answer = 0;
vector<bool> isVisitedVec;

void Func(map<int, vector<int>>& comMap, const int& i)
{
	isVisitedVec[i] = true;

	// 간선이 있다면
	if (comMap.count(i) > 0)
	{
		for (int j = 0; j < comMap[i].size(); j++)
		{
			if (isVisitedVec[comMap[i][j]] == true)
				continue;

			isVisitedVec[comMap[i][j]] = true;
			Func(comMap, comMap[i][j]);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	isVisitedVec.resize(n);

	map<int, vector<int>> comMap;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 자기 자신이거나 연결되어 있지 않은 경우
			if (i == j || computers[i][j] == 0)
				continue;

			comMap[i].emplace_back(j);
		}
	}

	int checkI = 0;
	while (true)
	{
		bool isNotVisited = false;
		for (int i = 0; i < n; i++)
		{
			if (isVisitedVec[i] == false)
			{
				isNotVisited = true;
				checkI = i;
				break;
			}
		}

		if (isNotVisited == false)
			break;

		Func(comMap, checkI);
		answer++;
	}

	return answer;
}