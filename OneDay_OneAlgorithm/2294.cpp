#include <iostream>
#include <vector>

int n = 0;
int k = 0;

std::vector<int> inputVec;
std::vector<int> originalCountVec;
std::vector<int> countVec;

const int Max = 10001;
int resultMin = Max;

void Func(int sum)
{
	if (sum >= k)
	{
		// k���� �� ������ ��
		if (sum == k)
		{
			// ���� ���� ����
			int tempCount = 0;
			for (int i = 0; i < n; i++)
			{
				tempCount += originalCountVec[i] - countVec[i];
			}

			if (tempCount > 0 && tempCount < resultMin)
			{
				resultMin = tempCount;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (countVec[i] <= 0)
				continue;

			countVec[i]--;
			Func(sum + inputVec[i]);
			countVec[i]++;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> k;

	inputVec.resize(n);
	originalCountVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		// ���� �� �ִ� ������ ����
		originalCountVec[i] = k / inputVec[i];
	}

	countVec = originalCountVec;

	// �� ���� ���� �ð��ʰ�
	//Func(0);

	std::vector<int> dpVec(k+1);

	for (int i = 0; i < n; i++)
	{
		for (int j = inputVec[i]; j < k + 1; j++)
		{
			int temp = Max;

			// ������ ������ ���� �ε���
			int prevIndex = j - inputVec[i];

			// ������ ������ ������ 1�� ���ؾ���
			if (dpVec[prevIndex] != 0 || prevIndex == 0)
			{
				temp = dpVec[prevIndex] + 1;
			}

			// ������ų �� �ִٸ�
			if ((dpVec[j] == 0 || temp < dpVec[j]) && temp != Max)
			{
				dpVec[j] = temp;
			}
		}
	}

	// ���� �� ���� ��
	if (dpVec[k] == 0 || dpVec[k] == Max)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << dpVec[k];
	}

	return 0;
}
