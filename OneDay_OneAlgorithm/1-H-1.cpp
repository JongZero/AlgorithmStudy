// ������ �¾�����, ������ ������� ���� ��Ȯ�� �������� ����.
// 10���� ������ �迭�� �׳� �̸� �����ص� ��.
// ������ �ٽ��� �ּڰ��� ���ϴ� ���̾��ٰ� �ϴµ�, �� �κ��� ������.
// ���� 1�� ������ �ٽ� Ǯ���.

#include <bits/stdc++.h>
using namespace std;

int n, k, psum[100004];
int maxN = -100 * 100000 - 4;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		psum[i] = psum[i - 1] + input;
	}

	for (int i = k; i <= n; i++)
	{
		maxN = max(maxN, psum[i] - psum[i - k]);
	}
	cout << maxN;
}