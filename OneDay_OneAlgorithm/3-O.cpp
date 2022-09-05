#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
int n, m, h, c;
enum
{
	LEFT,
	RIGHT,
};
int visited[2][31][11];
vector<pa> garo;
vector<int> now;
int nowVisited[2][31][11];
bool isEnd = false;
void choice(int size, int r, int start)
{
	if (isEnd) return;
	if (now.size() == r)
	{
		// 다 뽑았다.
		for (int i = 0; i < r; i++)
		{
			int y, x;
			tie(y, x) = garo[now[i]];
			for (int j = 0; j < r; j++)
			{
				if (i == j) continue;
				int cy, cx;
				tie(cy, cx) = garo[now[j]];
				if (y == cy && abs(x - cx) == 1)
				{
					//cout << "가로선이 겹친다!\n";
					return;
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			int y, x;
			tie(y, x) = garo[now[i]];
			visited[RIGHT][y][x] = 1;
			visited[LEFT][y][x + 1] = 1;
		}

		// 잘 가는지 테스트한다.
		// (0, 0) ~ (0, m - 1)
		//cout << r << "--- 테스트 시작 ---\n";

		bool isOK = true;
		for (int i = 0; i < m; i++)
		{
			//cout << i << "번 테스트 : \n";
			memcpy(nowVisited, visited, sizeof(visited));
			int y = 0;
			int x = i;

			while (true)
			{
				if (nowVisited[RIGHT][y][x] == 1)
				{
					x++;
					nowVisited[LEFT][y][x] = 2;
					//cout << x << "\t오른쪽으로 한 칸 이동!\n";
				}
				else if (nowVisited[LEFT][y][x] == 1)
				{
					x--;
					nowVisited[RIGHT][y][x] = 2;
					//cout << x << "\t왼쪽으로 한 칸 이동!\n";
				}
				else
				{
					y++;
					//cout << x << "\t아래로 한 칸 이동!\n";
				}
				if (y >= n)
				{
					//cout << x << "에 도착함";
					if (x != i)
					{
						isOK = false;
						//cout << "  잘못도착!!!!";
					}
					//cout << '\n';
					break;
				}
			}
			if (!isOK) break;
		}
		if (isOK)
		{
			//cout << "테스트 통과 완료!\n";
			isEnd = true;
		}

		for (int i = 0; i < r; i++)
		{
			int y, x;
			tie(y, x) = garo[now[i]];
			visited[RIGHT][y][x] = 0;
			visited[LEFT][y][x + 1] = 0;
		}

		return;
	}
	for (int i = start + 1; i < size; i++)
	{
		now.push_back(i);
		choice(size, r, i);
		now.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> m >> h >> n;
	for (int i = 0; i < h; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		visited[RIGHT][a][b] = 1;	// 1,1에서 오른쪽으로 갈 수 있다.
		visited[LEFT][a][b + 1] = 1;// 1,2에서 왼쪽으로 갈 수 있다.
	}
	// 가로선 후보들을 찾는다.
	int y = 0;
	int x = 0;
	while (true)
	{
		if (!visited[RIGHT][y][x] && !visited[LEFT][y][x])
		{
			bool is = true;
			if (x + 1 < m - 1 && visited[RIGHT][y][x + 1])
			{
				is = false;
			}
			if (is)
			{
				// 후보에 등록한다.
				garo.push_back({ y, x });
			}
		}

		y++;
		if (y >= n)
		{
			y = 0;
			x++;
			if (x >= m - 1) break;
		}
	}
	while (true)
	{
		// 가로선 후보들 중에 c개를 뽑는다. 최솟값이므로 0부터 시작
		// 뽑을 때 가로선끼리 겹치면 안 된다. 뽑은 후 가로선을 만든다.
		// 다 뽑으면, 1 -> 1, 2 -> 2, ...로 잘 가는지 테스트한다.
		// 잘 갔다면 끝
		// 잘 못갔다면 가로선 증가해서 다시 반복
		choice(garo.size(), c, -1);
		now.clear();
		if (isEnd) break;
		c++;
		if (c > 3) break;
	}
	if (isEnd) cout << c;
	else cout << -1;
}