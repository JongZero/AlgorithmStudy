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
		// �� �̾Ҵ�.
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
					//cout << "���μ��� ��ģ��!\n";
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

		// �� ������ �׽�Ʈ�Ѵ�.
		// (0, 0) ~ (0, m - 1)
		//cout << r << "--- �׽�Ʈ ���� ---\n";

		bool isOK = true;
		for (int i = 0; i < m; i++)
		{
			//cout << i << "�� �׽�Ʈ : \n";
			memcpy(nowVisited, visited, sizeof(visited));
			int y = 0;
			int x = i;

			while (true)
			{
				if (nowVisited[RIGHT][y][x] == 1)
				{
					x++;
					nowVisited[LEFT][y][x] = 2;
					//cout << x << "\t���������� �� ĭ �̵�!\n";
				}
				else if (nowVisited[LEFT][y][x] == 1)
				{
					x--;
					nowVisited[RIGHT][y][x] = 2;
					//cout << x << "\t�������� �� ĭ �̵�!\n";
				}
				else
				{
					y++;
					//cout << x << "\t�Ʒ��� �� ĭ �̵�!\n";
				}
				if (y >= n)
				{
					//cout << x << "�� ������";
					if (x != i)
					{
						isOK = false;
						//cout << "  �߸�����!!!!";
					}
					//cout << '\n';
					break;
				}
			}
			if (!isOK) break;
		}
		if (isOK)
		{
			//cout << "�׽�Ʈ ��� �Ϸ�!\n";
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
		visited[RIGHT][a][b] = 1;	// 1,1���� ���������� �� �� �ִ�.
		visited[LEFT][a][b + 1] = 1;// 1,2���� �������� �� �� �ִ�.
	}
	// ���μ� �ĺ����� ã�´�.
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
				// �ĺ��� ����Ѵ�.
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
		// ���μ� �ĺ��� �߿� c���� �̴´�. �ּڰ��̹Ƿ� 0���� ����
		// ���� �� ���μ����� ��ġ�� �� �ȴ�. ���� �� ���μ��� �����.
		// �� ������, 1 -> 1, 2 -> 2, ...�� �� ������ �׽�Ʈ�Ѵ�.
		// �� ���ٸ� ��
		// �� �����ٸ� ���μ� �����ؼ� �ٽ� �ݺ�
		choice(garo.size(), c, -1);
		now.clear();
		if (isEnd) break;
		c++;
		if (c > 3) break;
	}
	if (isEnd) cout << c;
	else cout << -1;
}