#include <bits/stdc++.h>
using namespace std;


int n;
int a[1000001];
int ret[1000001];
stack<int> stk;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	memset(ret, -1, sizeof(ret));

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (stk.size())
		{
			int size = stk.size();
			for (int j = 0; j < size; j++)
			{
				int t = stk.top(); stk.pop();
				if (a[t] < a[i])
				{
					ret[t] = a[i];
				}
				else
				{
					stk.push(t);
					break;
				}
			}
		}
		
		stk.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ret[i] << ' ';
	}
}