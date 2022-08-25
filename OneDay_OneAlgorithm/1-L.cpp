#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> now;

void combi(int n, int r, int start, int& ret, int m)
{
	if (now.size() == r)
	{
		int sum = accumulate(now.begin(), now.end(), 0);
		if (sum == m)
			ret++;
	}
	for (int i = start + 1; i < n; i++)
	{
		now.push_back(v[i]);
		combi(n, r, i, ret, m);
		now.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	int m = 0;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	// 조합이다.
	//int ret = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = i + 1; j < n; j++)
	//	{
	//		if (v[i] + v[j] == m)
	//			ret++;
	//	}
	//}
	//cout << ret;

	// 재귀로 풀면 시간초과 난다.
	// 그러나?
	if (m > 200000)
	{
		cout << 0;
		return 0;
	}
	int ret = 0;
	combi(n, 2, -1, ret, m);
	cout << ret;
}