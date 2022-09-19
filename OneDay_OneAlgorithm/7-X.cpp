#include <bits/stdc++.h>
using namespace std;

int n, m, c, ret, dp[14][11][21], a[21], visited[21];


int func2(int start, int cnt, int w)
{
	//cout << start << ", " << cnt << ", " << w << '\n';
	//
	//for (int i = 1; i <= n; i++)
	//	cout << visited[i] << ' ';
	//cout << '\n';

	int& d = dp[start][cnt][w];
	if (d != -1) return d;
	d = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		if (a[i] > c) continue;
		w += a[i];
		visited[i] = 1;
		if (w <= c) 
		{
			d = max(d, func2(i, cnt, w) + 1);
		}
		else
		{
			if (cnt > 1)
				d = max(d, func2(i, cnt - 1, a[i]) + 1);
		}
		visited[i] = 0;
		w -= a[i];
	}
	//cout << start << ", " << cnt << ", " << w << " d: " << d << '\n';
	return d;
}


int func(int idx, int cnt, int w)
{
	cout << idx << ", " << cnt << ", " << w << '\n';

	if (idx >= n - 1) return 0;
	if (cnt < 0) return 0;
	int& d = dp[idx][cnt][w];
	if (d != -1) return d;
	d = 0;

	// 현재 보석을 챙기지 않는다.
	d = max(d, func(idx + 1, cnt, w));
	//cout << "보석 안챙김: ";
	//cout << idx << ", " << cnt << ", " << w << ' ';
	//cout << "d: " << d << '\n';

	// 현재 보석을 챙긴다.
	int temp = w;
	if (a[idx] <= c)
	{
		if (w + a[idx] > c)
		{
			d = max(d, func(idx + 1, cnt - 1, a[idx]) + 1);
			temp = a[idx];
		}
		else
		{
			d = max(d, func(idx + 1, cnt, w + a[idx]) + 1);
			temp = w + a[idx];
		}
	}
	cout << idx << ", " << cnt << ", " << w << ' ';
	cout << "d: " << d << '\n';

	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	cout << func2(0, m, 0);

	/*
	sort(a.begin(), a.end());
	do
	{
		//for (int i = 0; i < n; i++)
		//	cout << a[i] << ' ';
		//cout << '\n';

		int cnt = 0;
		int w = m;
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > c) continue;
			cnt++;
			temp += a[i];
			//cout << "temp: " << temp << '\n';
			if (temp > c)
			{
				//cout << "가방 무게초과\n 남은가방: ";
				w--;
				//cout << w << '\n';
				temp = a[i];
				if (w <= 0)
				{
					cnt--;
					break;
				}
			}
		}
		ret = max(ret, cnt);
		//cout << "ret: " << ret << '\n';
	} while (next_permutation(a.begin(), a.end()));

	cout << ret;
	*/
}