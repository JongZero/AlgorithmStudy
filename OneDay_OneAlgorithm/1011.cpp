#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// 1 - 1	1
// 2 - 2	1 1
// 3 - 3	1 1 1
// 4 - 3	1 2 1
// 5 - 4	1 2 1 1
// 6 - 4	1 2 2 1
// 7 - 5	1 2 2 1 1
// 8 - 5	1 2 2 2 1
// 9 - 5	1 2 3 2 1
// 10 - 6	1 2 3 2 1 1
// 11 - 6	1 2 3 2 2 1
// 12 - 6	1 2 3 3 2 1
// 13 - 7	1 2 3 3 2 1 1
// 14 - 7	1 2 3 3 2 2 1
// 15 - 7	1 2 3 3 3 2 1
// 16 - 7	1 2 3 4 3 2 1
// 17 - 8	1 2 3 4 3 2 1 1
// 18 - 8	1 2 3 4 3 2 2 1
// 19 - 8	1 2 3 4 3 3 2 1
// 20 - 8	1 2 3 4 4 3 2 1
// 21 - 9	1 2 3 4 4 3 2 1 1
// 22 - 9	1 2 3 4 4 3 2 2 1
// 23 - 9	1 2 3 4 4 3 3 2 1
// 24 - 9	1 2 3 4 4 4 3 2 1
// 25 - 9	1 2 3 4 5 4 3 2 1
// 26 - 10	1 2 3 4 5 4 3 2 1 1
// 27 - 10	1 2 3 4 5 4 3 2 2 1
// 28 - 10	1 2 3 4 5 4 3 3 2 1
// 29 - 10	1 2 3 4 5 4 4 3 2 1
// 30 - 10	1 2 3 4 5 5 4 3 2 1

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector <long long> numbers;
	long long c = pow(2, 31);

	// ���� Ƚ�� 
	int loopNum = 1;

	// (�� Ƚ���� 0�� �Ǹ� k�� 1 ����)
	int loopCount = 0;

	// �ִ� ���� Ƚ�� (�� Ƚ���� 0�� �Ǹ� ���� Ƚ�� ����)
	int maxLoopNum = loopNum * 2;

	// ���� ���� �̵� ��ġ�� �۵� Ƚ��, 1���� ����
	int k = 1;

	// i�� x, y�� ���� (�ּҺ��� �ִ���� �̸� ���س��´�.)
	// �̸� ���̸�ŭ�� Ƚ���� ���س��� �����Ѵ�.
	for (long long i = 1; i < c; i++)
	{
		loopCount--;
		maxLoopNum--;

		if (loopCount <= 0)
		{
			loopCount = loopNum;
			k++;

			numbers.push_back(i);
		}

		if (maxLoopNum <= 0)
		{
			loopNum++;
			maxLoopNum = loopNum * 2;
		}
	}

	int t = 0;
	cin >> t;

	for (int j = 0; j < t; j++)
	{
		long long x, y;
		cin >> x >> y;

		long long c = y - x;

		for (long long i = 0; i < numbers.size(); i++)
		{
			if (c < numbers[i])
			{
				k = i;
				break;
			}
		}

		cout << k << "\n";
	}

	return 0;
}