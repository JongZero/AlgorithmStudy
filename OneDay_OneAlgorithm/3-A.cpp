#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;

int n, m;
int a[51][51];
int ret = 987654321;

vector<pa> h;
vector<pa> c;
vector<int> combiNow;

int getDistance(int hI, int cI)
{
	int y = h[hI].first - c[cI].first;
	int x = h[hI].second - c[cI].second;
	if (y < 0) y *= -1;
	if (x < 0) x *= -1;
	return y + x;
}

void combi(int r, int start)
{
	if (combiNow.size() == r)
	{
		// 조합 완성
		// 치킨 거리를 구한다.
		int tempDis = 0;
		for (int i = 0; i < h.size(); i++)
		{
			int tempMin = 987654321;
			for (int j = 0; j < combiNow.size(); j++)
			{
				tempMin = min(getDistance(i, combiNow[j]), tempMin);
			}
			tempDis += tempMin;
		}
		//cout << "r : " << r << " tempDis : " << tempDis << "\n";
		if (tempDis < ret)
			ret = tempDis;
	}
	else
	{
		for (int i = start + 1; i < c.size(); i++)
		{
			combiNow.push_back(i);
			combi(r, i);
			combiNow.pop_back();
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) h.push_back({ i, j });
			if (a[i][j] == 2) c.push_back({ i, j });
		}
	}
	combi(m, -1);
	cout << ret;
}