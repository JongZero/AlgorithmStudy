#include <bits/stdc++.h>
using namespace std;

int n, root, r;
vector<int> a[51];

int tree(int s)
{
	int ret = 0;
	int cnt = 0;
	for (int ii : a[s])
	{
		if (r == ii) continue;
		cnt++;
		ret += tree(ii);
	}
	if (cnt == 0) return 1;
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		if (t == -1)
		{
			root = i;
		}
		else
		{
			a[t].push_back(i);
		}
	}
	cin >> r;
	if (r == root) cout << 0;
	else cout << tree(root);
}