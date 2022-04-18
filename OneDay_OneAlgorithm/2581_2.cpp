#include <iostream>
#include <map>

bool IsPrime(const int& num)
{
	bool isPrime = true;
	for (int i = 2; i < num; i++)
	{
		// 나눠떨어지는 게 있다면 소수가 아님
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int m(0), n(0);
	std::cin >> m >> n;

	// 총 개수
	int totalCount = n - m + 1;

	// 에라토스테네스의 체 활용해보자
	std::map<int, bool> numMap;		// 숫자, 소수인지

	// 초기화
	for (int i = m; i <= n; i++)
	{
		numMap[i] = true;
	}
	
	// 소수의 배수는 소수가 아님
	for (int i = m; i <= n; i++)
	{
		// 이미 소수가 아닌 걸로 판단되었다면 pass
		if (numMap[i] == false)
		{
			continue;
		}

		// 소수인지 체크
		bool isPrime = false;
		for (int j = i; j <= n; j += i)
		{
			// 진짜 소수인지 체크
			if (numMap[j] == true)
			{
				isPrime = IsPrime(j);
			}

			// 소수가 아니라면, 소수의 배수임
			if (isPrime == false)
			{
				numMap[j] = false;
			}
		}
	}

	int sum = 0;
	int min = 10001;
	for (int i = m; i <= n; i++)
	{
		// 소수라면
		if (i > 1 && numMap[i] == true)
		{
			// 최소 체크
			if (i < min)
			{
				min = i;
			}

			sum += i;
		}
	}

	if (sum <= 0)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << sum << '\n';
		std::cout << min;
	}

	return 0;
}