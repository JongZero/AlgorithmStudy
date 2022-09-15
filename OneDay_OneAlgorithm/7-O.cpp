#include <bits/stdc++.h>
using namespace std;

enum eType
{
	White,	// 일반
	Red,	// 쌓여있는 순서를 반대로 바꿈
	Blue,	// 이동 방향을 반대로 하고 한 칸 이동
};

enum eDir
{
	Right = 1,
	Left,
	Up,
	Down,
};

struct Horse
{
	Horse(int _y, int _x, int _index, eDir _dir) : y(_y), x(_x), index(_index), dir(_dir) {}
	int y, x, index;
	eDir dir;
};

struct Tile
{
	deque<Horse*> q;
	eType type;
};

int n, k, ret = 1;

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };

Tile a[13][13];
vector<Horse*> h;
bool isGameEnd = false;

void printQ(deque<Horse*> q)
{
	cout << "[ ";
	while (q.size())
	{
		cout << q.front()->index << ' ';
		q.pop_front();
	}
	cout << "] \n";
}

int func(bool isReverse, int y, int x, int ny, int nx, int index)
{
	//cout << index << "번 말이";
	//cout << y << ", " << x << "에서 " << ny << ", " << nx << "로 움직이려고 함\n";

	deque<Horse*> nTempQ;
	if (isReverse)
	{
		nTempQ = a[ny][nx].q;
		a[ny][nx].q.clear();
		reverse(a[y][x].q.begin(), a[y][x].q.end());
	}

	//cout << y << ", " << x << "의 q size: " << a[y][x].q.size() << '\n';
	//cout << ny << ", " << nx << "의 q size: " << a[ny][nx].q.size() << '\n';

	deque<Horse*> tempQ;
	bool isFind = false;
	while (a[y][x].q.size())
	{
		Horse* horse = a[y][x].q.front();
		if (isReverse)
			horse = a[y][x].q.back();

		if (horse->index == index)
			isFind = true;

		if (isFind)
		{
			horse->y = ny;
			horse->x = nx;

			//cout << horse->index << "번 말 " << ny << ", " << nx << "로 이동함\n";
			if (!isReverse)
				a[ny][nx].q.push_back(horse);
			else
				a[ny][nx].q.push_front(horse);
		}
		else
			tempQ.push_back(horse);

		if (!isReverse)
			a[y][x].q.pop_front();
		else
			a[y][x].q.pop_back();
	}
	a[y][x].q = tempQ;

	while (nTempQ.size())
	{
		a[ny][nx].q.push_front(nTempQ.back());
		nTempQ.pop_back();
	}

	//cout << "이동 끝!\n";
	//cout << y << ", " << x << "의 q size: " << a[y][x].q.size() << '\n';
	//cout << ny << ", " << nx << "의 q size: " << a[ny][nx].q.size() << '\n';

	//printQ(a[y][x].q);
	//printQ(a[ny][nx].q);

	return a[ny][nx].q.size();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			a[i][j].type = (eType)t;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		int y, x, t;
		cin >> y >> x >> t;
		Horse* horse = new Horse(y, x, i, (eDir)t);
		h.push_back(horse);
		a[y][x].q.push_back(horse);
	}
	while (true)
	{
		//cout << ret << "번 턴 시작!!\n";

		int index = 1;
		for (Horse* horse : h)
		{
			int y = horse->y;
			int x = horse->x;
			int ny = y + dy[horse->dir];
			int nx = x + dx[horse->dir];

			eType t;
			if (ny <= 0 || nx <= 0 || ny > n || nx > n) t = eType::Blue;
			else t = a[ny][nx].type;

			int cnt = 0;

			switch (t)
			{
			case White:
			{
				cnt = func(false, y, x, ny, nx, index);
			}
				break;
			case Red:
			{
				cnt = func(true, y, x, ny, nx, index);
			}
				break;
			case Blue:
			{
				switch (horse->dir)
				{
				case Right:
					horse->dir = Left;
					break;
				case Left:
					horse->dir = Right;
					break;
				case Up:
					horse->dir = Down;
					break;
				case Down:
					horse->dir = Up;
					break;
				}
				ny = y + dy[horse->dir];
				nx = x + dx[horse->dir];
				if (a[ny][nx].type != eType::Blue && ny > 0 && nx > 0 && ny <= n && nx <= n)
				{
					if (a[ny][nx].type == eType::White)
						cnt = func(false, y, x, ny, nx, index);
					else
						cnt = func(true, y, x, ny, nx, index);
				}
			}
				break;
			}

			//cout << index << "번 말 차례 cnt: " << cnt << '\n';
			if (cnt >= 4) 
			{
				isGameEnd = true; 
				break;
			}
			index++;
		}
		if (isGameEnd) break;
		ret++;
		if (ret > 1000) break;
	}
	if (isGameEnd) cout << ret;
	else cout << -1;
}