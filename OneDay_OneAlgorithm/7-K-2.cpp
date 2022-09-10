#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51][51]; //dp�� y,x���� �������� � �湮�ߴ���, ������ ��� �������� �湮�ϰ�Դ����� �����س���. �� ���¿��� n,m�� �湮�ϴ� ����� ���̴�.
											// ����°�� �� �� ��Ȯ�ϰ� ���ؼ�, �� ���� �����ǿ� �湮�� �� �ִ��� ī��Ʈ�̴�.
int func(int y, int x, int cnt, int prevv)
{
	//cout << y << ", " << x << '\n';
	if (cnt < 0) return 0;
	if (y > n || x > m) return 0;
	if (y == n && x == m)	// �п��� ������ ���
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prevv) return 1;	// �п��� �������� ���� �ִ�. �׷��ٸ� �� ��쿡�� cnt�� 1�̾�� ��.
		return 0;
	}
	if (dp[y][x][cnt][prevv] != -1) return dp[y][x][cnt][prevv];
	dp[y][x][cnt][prevv] = 0;
	if (a[y][x] == 0) dp[y][x][cnt][prevv] = (func(y + 1, x, cnt, prevv) + func(y, x + 1, cnt, prevv)) % 1000007;
	else if (a[y][x] > prevv) dp[y][x][cnt][prevv] = (func(y + 1, x, cnt - 1, a[y][x]) + func(y, x + 1, cnt - 1, a[y][x])) % 1000007;

	//cout << y << ", " << x << '\n';
	//cout << " dp: " << dp[y][x][cnt][prevv] << '\n';

	return dp[y][x][cnt][prevv];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++)
	{
		int b, c;
		cin >> b >> c;
		a[b][c] = i;
	}
	for (int i = 0; i <= c; i++)
	{
		//cout << "=============\n";
		cout << func(1, 1, i, 0) << ' ';
	}
}