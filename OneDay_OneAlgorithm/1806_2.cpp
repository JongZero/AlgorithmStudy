#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int s = 0;
	std::cin >> n >> s;

	int resultMin = 100001;	// 최대 길이로 초기화

	std::vector<int> inputVec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];
	}

	int start = 0;
	int end = 0;

	int count = 1;
	int sum = 0;
	while (start < n)
	{
		// s ~ e까지 더함 (부분합)
		if (sum >= s)
		{
			sum -= inputVec[start];
			start++;
			count--;

			if (count < resultMin)
				resultMin = count;
		}
		else
		{
			if (end > n - 1)
			{
				end = n - 1;
				break;
			}
			else
			{
				sum += inputVec[end];

				end++;
				count++;
			}
		}
	}

	if (resultMin == 100001)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << resultMin;
	}

	return 0;
}