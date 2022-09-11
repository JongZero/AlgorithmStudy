#include <bits/stdc++.h>
using namespace std;

struct Tile
{
	vector<int> trees;
	queue<int> deadTrees;
	int energy = 5;
};

int n, m, k;
int aaa[11][11];
Tile a[11][11];
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> aaa[i][j];
			//a[i][j].energy += aaa[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y].trees.push_back(z);
	}
	while (k--)
	{
		//cout << "--- ��� ��Ȳ ---\n";
		//for (int i = 1; i <= n; i++)
		//{
		//	for (int j = 1; j <= n; j++)
		//	{
		//		cout << a[i][j].energy << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		// ��
		//cout << "======= �� ======= \n";
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				//cout << i << ", " << j << "�� Ÿ�� ���� ����\n";
				Tile& t = a[i][j];
				sort(t.trees.begin(), t.trees.end());
				vector<int> tempTrees;
				for (int k = 0; k < t.trees.size(); k++)
				{
					int now = t.energy;
					now -= t.trees[k];
					// ����� ����
					if (now < 0)
					{
						//cout << "����� �����ϴ�. ��������. ������ ����: " << t.trees[k] << " Ÿ���� ���� ���: " << now << '\n';
						t.deadTrees.push(t.trees[k]);
					}
					else
					{
						t.trees[k]++;
						tempTrees.push_back(t.trees[k]);
						t.energy = now;
						//cout << "�� �� �Ծ���. ������ ����: " << t.trees[k] << " Ÿ���� ���� ���: " << now << '\n';
					}
				}
				t.trees = tempTrees;
			}
		}
		// ����
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				Tile& t = a[i][j];
				while (t.deadTrees.size())
				{
					int tree = t.deadTrees.front();
					t.deadTrees.pop();
					t.energy += (tree / 2);
				}
			}
		}
		// ����
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				Tile& t = a[i][j];
				for (int k = 0; k < t.trees.size(); k++)
				{
					if (t.trees[k] % 5 == 0)
					{
						for (int p = 0; p < 8; p++)
						{
							int ny = i + dy[p];
							int nx = j + dx[p];
							if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
							a[ny][nx].trees.push_back(1);
						}
					}
				}
			}
		}
		// �ܿ�
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				Tile& t = a[i][j];
				t.energy += aaa[i][j];
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ret += a[i][j].trees.size();
		}
	}
	cout << ret;
}