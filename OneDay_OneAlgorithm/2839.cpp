#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	// 3ų�α׷� ���� ������ 5ų�α׷� ���� ���� �迭
	// �� �߿� ���� ���� ���� ã�� ���̴�.
	vector<int> k3;
	vector<int> k5;

	// i -> 3ų�α׷� ���� ����, k -> 5ų�α׷� ���� ����
	// 1�� ������Ű�鼭 3 * i + 5 * k�� n�� �Ǵ� ������ ã�� ���̴�.
	// n���� �� ū ���� ���´ٸ� break�� Ż��
	int i = 0;
	int k = 0;

	// i�ϳ���, k�� �� ���ս��Ѻ� ( i = 0, k = 0,1,2,3,4... // i = 1, k = 0,1,2,3,4...)
	while (true)
	{
		k = 0;
		while (true)
		{
			int now = 3 * i + 5 * k;

			if (now > n)
			{
				break;
			}

			if (now == n)
			{
				k3.push_back(i);
				k5.push_back(k);
			}

			k++;
		}

		if (3 * i > n)
		{
			break;
		}

		i++;
	}

	i = 0;
	k = 0;
	// k�ϳ���, i�� �� ���ս��Ѻ� ( k = 0, i = 0,1,2,3,4... // k = 1, i = 0,1,2,3,4...)
	while (true)
	{
		i = 0;
		while (true)
		{
			int now = 3 * i + 5 * k;

			if (now > n)
			{
				break;
			}

			if (now == n)
			{
				k3.push_back(i);
				k5.push_back(k);
			}

			i++;
		}

		if (3 * k > n)
		{
			break;
		}

		k++;
	}
	
	// ���� ���� ���̵Ǵ� i, k ������ ã�´�.
	if (k3.size() > 0)
	{
		int sum = 100000;
		for (int i = 0; i < k3.size(); i++)
		{
			if (k3[i] + k5[i] < sum)
			{
				sum = k3[i] + k5[i];
			}
		}

		cout << sum;
	}
	else
	{
		cout << -1;
	}

	return 0;
}