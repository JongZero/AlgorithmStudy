#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	// �յ��� ��� ���ؼ� ����
	vector<int> sums;

	for (int i = 0; i < n - 2; i++)
	{
		// 5 6 7
		// 5 6 8
		// 5 6 9
		// 5 7 8
		// 5 7 9
		// 5 8 9
		// 6 7 8
		// ...

		// �����ε����� �ٷ� ���� �ε���
		int index1 = 1;

		// �����ε����� �������� �ε���
		int index2 = 2;

		// �� ������ ��
		int sum = 0;

		while (true)
		{
			while (true)
			{
				sum += numbers[i];
				sum += numbers[i + index1];
				sum += numbers[i + index2];

				// ������ ���ڸ� �ϳ��� �ε����� ������Ű�鼭 sum�� ���Ѵ�.
				index2++;

				sums.push_back(sum);
				sum = 0;

				// ������ ���ڰ� �迭�� �������� �������� �� index1�� ���������ش�.
				if (i + index2 > n - 1)
				{
					break;
				}
			}
			index1++;
			index2 = index1 + 1;

			// �߰� ���ڰ� �迭�� ������ - 1 �� �������� �� i�� ���������ش�.
			if ((i + index1) >= n - 1)
			{
				break;
			}
		}
	}

	// �� �߿��� ���� ū ���ڸ� ���Ѵ�.
	int max = 0;
	for (int i = 0; i < sums.size(); i++)
	{
		if (sums[i] <= m && max < sums[i])
			max = sums[i];
	}

	// ���
	cout << max;

	return 0;
}