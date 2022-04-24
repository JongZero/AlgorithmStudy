#include <iostream>
#include <vector>

int n = 0;
int s = 0;
std::vector<int> inputVec;
std::vector<int> checkVec;
int countMin = 100001;

/* 모든 경우를 탐색하면, 시간 초과
void Func(int count, int sum)
{
	if (sum >= s)
	{
		if (count < countMin)
		{
			countMin = count;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (checkVec[i] == 0)
				continue;

			sum += checkVec[i];
			checkVec[i] = 0;
			Func(count + 1, sum);
			checkVec[i] = inputVec[i];
			sum -= checkVec[i];
		}
	}
}
*/

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> s;

	inputVec.resize(n);

	std::vector<int> resultVec;

	int start = 0;
	int end = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		// 부분 합 구하기
		sum += inputVec[i];

		end++;

		// 부분 합이 s보다 크다면 최소인지 체크
		if (sum >= s)
		{
			// start를 하나씩 옮기면서, s 이상이고, 최소인지 체크
			while (true)
			{
				int sub = end - start;

				if (sum < s)
				{
					break;
				}

				// 최소인지 체크
				if (sub < countMin)
				{
					countMin = sub;
				}

				// 부분합에서 빠진 부분을 sum에서 제외
				sum -= inputVec[start];
				start++;
			}
		}
	}

	//checkVec = inputVec;
	//Func(0, 0);

	if (countMin == 100001)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << countMin;
	}

	return 0;
}
