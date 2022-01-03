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

	// 합들을 모두 구해서 저장
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

		// 시작인덱스의 바로 다음 인덱스
		int index1 = 1;

		// 시작인덱스의 다음다음 인덱스
		int index2 = 2;

		// 세 숫자의 합
		int sum = 0;

		while (true)
		{
			while (true)
			{
				sum += numbers[i];
				sum += numbers[i + index1];
				sum += numbers[i + index2];

				// 마지막 숫자를 하나씩 인덱스를 증가시키면서 sum을 구한다.
				index2++;

				sums.push_back(sum);
				sum = 0;

				// 마지막 숫자가 배열의 마지막에 도달했을 때 index1을 증가시켜준다.
				if (i + index2 > n - 1)
				{
					break;
				}
			}
			index1++;
			index2 = index1 + 1;

			// 중간 숫자가 배열의 마지막 - 1 에 도달했을 때 i를 증가시켜준다.
			if ((i + index1) >= n - 1)
			{
				break;
			}
		}
	}

	// 합 중에서 가장 큰 숫자를 구한다.
	int max = 0;
	for (int i = 0; i < sums.size(); i++)
	{
		if (sums[i] <= m && max < sums[i])
			max = sums[i];
	}

	// 출력
	cout << max;

	return 0;
}