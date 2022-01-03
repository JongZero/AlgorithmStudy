#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> kgVec(n);
	vector<int> cmVec(n);

	for (int i = 0; i < n; i++)
	{
		int kg, cm;
		cin >> kg >> cm;

		kgVec[i] = kg;
		cmVec[i] = cm;
	}

	// 자신보다 덩치가 더 큰 사람의 수
	vector<int> countVec(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			// 키도 더 크고 kg도 더 크다면
			if (kgVec[i] < kgVec[j]
				&& cmVec[i] < cmVec[j])
			{
				countVec[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << countVec[i] + 1 << " ";
	}

	return 0;
}