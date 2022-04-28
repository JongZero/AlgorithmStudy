#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int Max = 10;
map<int, bool> numMap;
vector<long long> resultVec;

void Func(int count, string s, int end)
{
	if (count != end)
	{
		for (int i = Max - 1; i >= 0; i--)
		{
			if (numMap[i] == true)
				continue;

			char c = i + '0';

			if (s.size() > 0)
			{
				int last = s[s.size() - 1] - '0';
				if (last <= i)
				{
					continue;
				}
			}

			numMap[i] = true;
			Func(count + 1, s + c, end);
			numMap[i] = false;
		}
	}
	else
	{
		// 저장
		resultVec.emplace_back(stoll(s));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// 10보다 작다면 n == x
	if (n < 10)
	{
		std::cout << n;
		return 0;
	}

	for (int i = 0; i < Max; i++)
	{
		numMap[i] = false;
	}

	for (int i = 1; i < Max + 1; i++)
	{
		Func(0, "", i);
	}

	sort(resultVec.begin(), resultVec.end());

	if (resultVec.size() > n)
	{
		std::cout << resultVec[n];
	}
	else
	{
		std::cout << -1;
	}

	return 0;
}
