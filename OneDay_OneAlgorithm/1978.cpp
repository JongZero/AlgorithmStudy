#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> numbers;	// ���� �迭
	int count = 0;			// �Ҽ��� �����

	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;

		if (a > 1)
		{
			numbers.push_back(a);
		}
	}

	// �Ҽ����� �Ǻ�
	for (int i = 0; i < numbers.size(); i++)
	{
		// �Ҽ���� ����
		bool isPrime = true;

		for (int j = 2; j < numbers[i]; j++)
		{
			// �Ҽ��� �ƴ� ������ �˻�
			if (numbers[i] % j == 0)
			{
				isPrime = false;
			}
		}

		if (isPrime == true)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}