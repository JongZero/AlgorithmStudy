#include <bits/stdc++.h>
using namespace std;

// 1189, 컴백홈
/*
int r, c, k, ret;
char a[6][6];
int visited[6][6];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void func2(int y, int x, int dis)
{
	if (dis == k)
	{
		// 집인 경우
		if (y == 0 && x == c - 1) ret++;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 'T') continue;
			visited[y][x] = 1;
			func2(ny, nx, dis + 1);
			visited[y][x] = 0;
		}
	}
}

int main2()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}
	//visited[r - 1][0] = 1;
	func2(r - 1, 0, 1);
	cout << ret;
	return 0;
}
*/

// 17825, 주사위 윷놀이

int blues[] = { 5, 10, 15 };	// 20미만 5로 나눴을때 나눠떨어지는 수
//int blueRoute[4][8] = { {0, },
//						{0, },
//						{0, 22, 24, 25, 30, 35, 40, 0}, 
//						{0, 28, 27, 26, 25, 30, 35, 40} };

int route[4][46] = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
					22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
					{0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30,
					35, 40, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
					22, 24, 25, 30, 35, 40, 0, 0, 0, 0 },
					{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
					22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 
					35, 40} };

int go[10];
int retScore = 0;
int now[4];
int routeNum[4];
int isEnd[4];

void func(int goCount, int score)
{
	if (goCount == 9)
	{
		if (retScore < score)
		{
			retScore = score;
			//cout << "현재 최대 점수 : " << retScore << '\n';
		}
		return;
	}

	//cout << "goCount : " << goCount << '\n';
	//cout << "score : " << score << '\n';

	int per = goCount;
	if (per > 3) per = 3;

	for (int i = 0; i <= per; i++)
	{
		if (isEnd[i]) continue;

		int tScore = 0;

		now[i] += go[goCount];

		//cout << i << "번 말 " << go[goCount] << "칸 이동함." << '\n';
		//cout << i << "번 말 현재 위치 : " << now[i] << '\n';

		tScore = route[routeNum[i]][now[i]];

		if (tScore == 0)
		{
			isEnd[i] = 1;
		}

		//cout << i << "번 말 점수 : " << tScore << '\n';

		if (now[i] < 20 && now[i] % 5 == 0 && routeNum[i] == 0)
		{
			routeNum[i] = now[i] / 5;
		}

		score += tScore;
		func(goCount + 1, score);
		score -= tScore;
		now[i] -= go[goCount];
		if (isEnd[i]) isEnd[i] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 현재 시작 지점이 5, 10, 15중 하나라면 root 변경
	// 아니라면 일반 루트
	int malCount = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> go[i];
	}
	func(0, 0);
	cout << retScore;

	return 0;
}

