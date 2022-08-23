#include <bits/stdc++.h>
using namespace std;

vector<int> v;
bool isEnd = false;
void Combi(int n, int r, int start, vector<int>& input)
{
	if (isEnd) return;
	if (v.size() == r)
	{
		int sum = 0;
		for (int i = 0; i < r; i++)
		{
			sum += v[i];
		}
		if (sum == 100)
		{
			sort(v.begin(), v.end(), less<int>());
			for (int i = 0; i < r; i++)
			{
				cout << v[i] << '\n';
			}
			// 프로그램 종료 코드 뭐였지?
			isEnd = true;
		}
	}

	for (int i = start + 1; i < n; i++)
	{
		v.push_back(input[i]);
		Combi(n, r, i, input);
		v.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 9C7
	int n = 9;
	int r = 7;
	vector<int> input(n);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	Combi(n, r, -1, input);
}