#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	std::vector<std::pair<int, int>> inputVec;
	std::vector<int> vec(n + 1);

	int currentMax = 0;
	for (int i = 1; i < n + 1; i++)
	{
		int t = 0;
		int p = 0;

		std::cin >> t >> p;

		if (currentMax < vec[i])
		{
			currentMax = vec[i];
		}

		// ������ ���ڰ� �ִ����ڸ� �������
		int endDate = i + t;
		if (endDate > n)
		{
			continue;
		}

		// �� ����ٸ�, ���� ��¥������ �ִ� ����,
		// ���� ��¥�� ���� ��
		if (currentMax + p > vec[endDate])
		{
			vec[endDate] = currentMax + p;
		}
	}

	std::cout << currentMax;


	return 0;
}