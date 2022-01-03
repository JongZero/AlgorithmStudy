#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 일 테이블
	string dayTable[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	// 2007 월 테이블 (몇 일까지 있는지)
	int thirtyOne[7] = { 1,3,5,7,8,10,12 };
	int thirty[4] = { 4,6,9,11 };

	map<int, int> monthTable;
	for (int i = 0; i < 7; i++)
	{
		monthTable[thirtyOne[i]] = 31;
	}

	for (int i = 0; i < 4; i++)
	{
		monthTable[thirty[i]] = 30;
	}

	monthTable[2] = 28;

	// 2007년 전체 요일 테이블
	map<string, string> yearMap;

	int dayCount = 0;
	for (auto it : monthTable)
	{
		for (int i = 0; i < it.second; i++)
		{
			yearMap[to_string(it.first) + "_" + to_string(i + 1)] = dayTable[dayCount];
			dayCount++;

			if (dayCount > 6)
			{
				dayCount = 0;
			}
		}
	}

	string month, day;
	cin >> month >> day;

	string monthDay = month + "_" + day;

	for (auto it : yearMap)
	{
		if (it.first == monthDay)
		{
			cout << it.second;
			break;
		}
	}

	return 0;
}