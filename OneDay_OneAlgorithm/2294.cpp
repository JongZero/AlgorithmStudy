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
		// k원에 딱 떨어질 때
		if (sum == k)
		{
			// 쓰인 개수 조사
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

		// 쓰일 수 있는 동전의 개수
		originalCountVec[i] = k / inputVec[i];
	}

	countVec = originalCountVec;

	// 다 도는 것은 시간초과
	//Func(0);

	std::vector<int> dpVec(k+1);

	for (int i = 0; i < n; i++)
	{
		for (int j = inputVec[i]; j < k + 1; j++)
		{
			int temp = Max;

			// 이전에 누적된 개수 인덱스
			int prevIndex = j - inputVec[i];

			// 이전에 누적된 개수에 1을 더해야함
			if (dpVec[prevIndex] != 0 || prevIndex == 0)
			{
				temp = dpVec[prevIndex] + 1;
			}

			// 누적시킬 수 있다면
			if ((dpVec[j] == 0 || temp < dpVec[j]) && temp != Max)
			{
				dpVec[j] = temp;
			}
		}
	}

	// 구할 수 없을 때
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
