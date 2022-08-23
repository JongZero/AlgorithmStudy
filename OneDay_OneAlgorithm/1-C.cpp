#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	vector<pair<int, int>> parkTime(3);
	int min = 101;
	int max = 0;
	int times[101] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;

		parkTime[i].first = start;
		parkTime[i].second = end;

		if (start < min)
			min = start;
		if (end > max)
			max = end;

		for (int j = start; j < end; j++)
			times[j]++;
	}
	
	int result = 0;
	for (int i = min; i <= max; i++)
	{
		if (times[i] == 1)
			result += 1 * a;
		else if (times[i] == 2)
			result += 2 * b;
		else if (times[i] == 3)
			result += 3 * c;
	}

	cout << result;
}

// 시각은 이상 미만이다.
//  시작	  ~	  끝
// (이상)	(미만)