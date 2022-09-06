#include <bits/stdc++.h>
using namespace std;

int n, m, h, ret = 1e9;
int visited[31][11];

bool test()
{
	//cout << "�׽�Ʈ���� --------\n";
	for (int i = 1; i <= m; i++)
	{
		//cout << "���� �׽�Ʈ : " << i << '\n';
		int now = i;
		for (int j = 1; j <= n; j++)
		{
			if (visited[j][now]) now++;
			else if (visited[j][now - 1]) now--;
		}
		//cout << now << "�� ������\n";
		if (now != i) 
		{ 
			//cout << "�׽�Ʈ ����!\n";
			return false; 
		}
	}
	return true;
}

void func(int y, int x, int cnt)
{
	//cout << "{ " << y << ", " << x << " }" << "cnt : " << cnt << '\n';
	if (cnt > 3 || cnt >= ret)
	{
		return;
	}
	if (test() == true)
	{
		//cout << "�׽�Ʈ ����\n";
		ret = min(ret, cnt);
		return;
	}
	for (int j = x; j < m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (visited[i][j]) continue;
			if (visited[i][j + 1]) continue;
			if (visited[i][j - 1]) continue;
			visited[i][j] = 1;
			func(i, j, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> m >> h >> n;
	for (int i = 1; i <= h; i++)
	{
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
		//cout << "{ " << a << ", " << b << " }\n";
	}
	func(1, 1, 0);
	if (ret == 1e9) cout << -1;
	else cout << ret;
}