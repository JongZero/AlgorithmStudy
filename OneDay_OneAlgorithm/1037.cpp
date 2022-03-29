#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;
	std::vector<int> divisorVec(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> divisorVec[i];
	}

	// 순서대로 정렬
	sort(divisorVec.begin(), divisorVec.end());

	const int Max = 1000000;
	const int Min = 2;

	unsigned int result = 0;
	for (unsigned int i = Min; i <= Max; i++)
	{
		if (i == 2401)
		{
			int ee = 0;
		}

		// 약수들로 나누어떨어지는지 검사
		bool check = true;
		for (int j = 0; j < n; j++)
		{
			// 약수와 같거나, 나누어떨어지지 않는다면
			// 패스
			if (i == divisorVec[j]
				|| i % divisorVec[j] != 0)
			{
				check = false;
				break;
			}
		}

		// 모두 나누어 떨어진다면
		if (check)
		{
			/// 진짜 약수인지 검증해야함
			// (예외) 입력 : 3 / 7 49 343 
			// -> 정답 : 2401
			// 이 예외 처리안했을 시 : 686
			// 686의 진짜 약수에는 2가 있다. 그러나 입력으로 들어온 3개의 숫자 중엔 2가 없음
			// 문제에서 진짜 약수가 '모두' 주어진다고 했으므로 틀리다.

			// 2부터 돌면서, 하나라도 입력으로 들어온 게 없으면 아웃
			bool isExist = false;
			for (int k = Min; k <= Max; k++)
			{
				// 나누어 떨어지는 수 중에
				if (i % k == 0)
				{
					for (int o = 0; o < n; o++)
					{
						// 입력으로 들어왔는가?
						// 안들어왔다면 꽝!
						if (k == divisorVec[o])
						{
							isExist = true;
							break;
						}
					}

					// 입력으로 들어온게 없다면 더 검사할 필요도 없이
					// 틀린 것이다. 틀린 이유는 54번줄부터
					if (!isExist)
						break;
				}
			}

			// 입력으로 모두 들어왔다면 맞는 결과
			if (isExist)
			{
				result = i;
				break;
			}
		}
	}

	std::cout << result;

	return 0;
}