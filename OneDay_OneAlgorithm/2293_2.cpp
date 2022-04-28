#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n >> k;

	// input
	std::vector<int> inputVec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];
	}

	// dp
	std::vector<int> dpVec(k + 1);

	// k�� 10�̶��, 1������ 10������ ����� ���� ���������ָ��
	// 0���� ����� �� 1���� ģ��.
	dpVec[0] = 1;
	for (int j = 0; j < n; j++)
	{
		for (int i = inputVec[j]; i < k + 1; i++)
		{
			dpVec[i] += dpVec[i - inputVec[j]];
		}
	}

	std::cout << dpVec[k];

	return 0;
}