// 정답은 맞았으나, 누적합 문제라는 것을 정확히 인지하지 못함.
// 10만개 정도의 배열은 그냥 미리 선언해도 됨.
// 문제의 핵심은 최솟값을 구하는 것이었다고 하는데, 이 부분은 맞췄음.
// 따라서 1번 정도만 다시 풀어본다.

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