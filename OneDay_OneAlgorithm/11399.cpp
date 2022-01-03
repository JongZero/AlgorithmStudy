#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> times(n);
	for (int i = 0; i < n; i++)
	{
		cin >> times[i];
	}

	// �ּҰ��� �������� ������ ����
	for (int i = 0; i < n - 1;)
	{
		if (times[i] > times[i + 1])
		{
			int temp = times[i];
			times[i] = times[i + 1];
			times[i + 1] = temp;

			i = 0;
		}
		else
		{
			i++;
		}
	}

	// �ð��� ���� ���Ѵ�.
	long long totalSum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			totalSum += times[j];
		}
	}

	cout << totalSum;

	return 0;
}