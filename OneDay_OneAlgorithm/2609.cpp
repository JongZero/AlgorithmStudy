#include <iostream>
#include <vector>

// 서로소인가?
bool isCoprime(int n1, int n2, int& divideNum)
{
	// 더 작은 수를 찾는다.
	int count = 0;
	if (n1 < n2)
	{
		count = n1;
	}
	else
	{
		count = n2;
	}

	// 공약수를 찾는다.
	for (int i = divideNum; i <= count; i++)
	{
		// i가 n1과 n2의 약수라면
		if (n1 % i == 0 && n2 % i == 0)
		{
			// 1이외의 공약수가 있으므로 서로소가 아님
			divideNum = i;
			return false;
		}
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n1(0), n2(0);
	std::cin >> n1 >> n2;

	// 최대 공약수를 구할 벡터
	std::vector<int> divideNumVec;

	// 서로소를 체크하면서 가장 작은 공약수를 꺼내온다.
	int divideNum = 2;
	
	// n1, n2가 서로소 일 때까지 반복
	while (!isCoprime(n1, n2, divideNum))
	{
		// 가장 작은 공약수로 나눈다.
		n1 /= divideNum;
		n2 /= divideNum;

		divideNumVec.push_back(divideNum);
	}
	
	// 한 개도 없다면 1이 최대공약수
	// 최소공배수는 두 수를 곱한 것
	if (divideNumVec.size() == 0)
	{
		std::cout << 1 << '\n';
		std::cout << n1 * n2;
	}
	else
	{
		// 최대 공약수 출력
		int max = 1;
		for (int i = 0; i < divideNumVec.size(); i++)
		{
			max *= divideNumVec[i];
		}
		std::cout << max << '\n';

		// 최소 공배수 출력
		std::cout << max * n1 * n2;
	}

	return 0;
}