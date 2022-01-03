#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	/// Mark1
	/// 1부터 n까지 루프돌며 구하기
	/// 당연히 시간초과로 미통과
	/// 옛날에 풀었었던 에라토스테네스의 체를 활용해보자
	/*
	int m, n;
	cin >> m >> n;

	// m ~ n 까지 소수를 구한다.
	for (int i = m; i <= n; i++)
	{
		// 1 이하는 소수가 될 수 없다.
		if (i <= 1)
		{
			continue;
		}
		
		bool isPrime = true;
		for (int j = 2; j < i; j++)
		{
			// 나눠떨어지는 수가 있다면 소수가 아님
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		// 소수라면 출력
		if (isPrime == true)
		{
			cout << i << "\n";
		}
	}
	*/
	
	/// Mark2
	/// 에라토스테네스의 체
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int m, n;
	cin >> m >> n;

	int* eratosVec = new int[1000001];

	// 일단 숫자를 배열에 넣는다.
	for (int i = 1; i <= n; i++)
	{
		eratosVec[i] = i;
	}
	
	for (int i = 2; i * i <= n; i++)
	{
		// 이미 에라토스테네스의 체로 걸러진 수라면 검사하지않고 넘어간다.
		if (eratosVec[i] == 1)
		{
			continue;
		}

		for (int j = i * i; j <= n; j += i)
		{
			eratosVec[j] = 1;
		}
	}

	// 출력한다.
	for (int i = m; i <= n; i++)
	{
		if (eratosVec[i] > 1)
		{
			cout << eratosVec[i] << "\n";
		}
	}

	delete[] eratosVec;

	return 0;
}