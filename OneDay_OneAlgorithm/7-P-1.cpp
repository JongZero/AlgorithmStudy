#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int INF = 987654321;
int af, bf, ar, br, ret = INF, ret2;
map<pa, int> m;
bool isEnd = false;
queue<pa> q;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> af >> bf >> ar >> br;
	q.push({ 0, 0 });
	while (true)
	{
		int size = q.size();
		if (size == 0) break;
		for (int i = 0; i < size; i++)
		{
			int a, b;
			tie(a, b) = q.front(); q.pop();
			if (a == ar && b == br)
			{
				isEnd = true;
				break;
			}
			if (m.find({ a, b }) != m.end())
			{
				continue;
			}
			m[{a, b}]++;

			// ���� a�� ���� ���� ä���.
			q.push({ af, b });
			// ���� b�� ���� ���� ä���.
			q.push({ a, bf });

			// ���� a�� ���� ��� ������.
			q.push({ 0, b });
			// ���� b�� ���� ��� ������.
			q.push({ a, 0 });

			// ���� a�� ���� b�� �״´�.
			if (a <= bf - b)
			{
				q.push({ 0, b + a });
			}
			else
			{
				q.push({ a - (bf - b), bf });
			}
			// ���� b�� ���� a�� �״´�.
			if (b <= af - a)
			{
				q.push({ a + b, 0 });
			}
			else
			{
				q.push({ af, b - (af - a) });
			}
		}
		if (isEnd) break;
		ret2++;
	}
	if (isEnd) cout << ret2;
	else cout << -1;
}