#include <iostream>
#include <vector>
#include <math.h>

unsigned long long factorial(const int n)
{
	unsigned long result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

void Func(int n, int m, std::vector<int> vec, int& count)
{
	// 조건 확인하고 맞으면 카운팅
	bool check = false;
	
	// 가장 처음이 m-n을 넘어선 경우
	if (vec.front() > m - n)
	{
		check = true;
	}

	// 가장 마지막이 m을 넘어선 경우
	if (vec.back() >= m)
	{
		check = true;
	}

	// 배열의 다음이 이전보다 큰 지 확인
	//if (check == false)
	//{
	//	int prevNum = vec.front();
	//	for (int i = 1; i < vec.size(); i++)
	//	{
	//		if (vec[i] <= prevNum)
	//		{
	//			check = true;
	//			break;
	//		}
	//	}
	//}
	
	// 모든 조건 통과
	if (check == false)
	{
		count++;
	}
		
	// 어느 부분을 증가시킬 것인가?
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (vec[i] < m)
		{
			vec[i]++;
			Func(n, m, vec, count);
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n >> m;

		// 분자
		std::vector<int> numeratorVec;
		//unsigned long long numerator = 1;
		for (int i = n + 1; i <= m; i++)
		{
			numeratorVec.emplace_back(i);
		}

		// 분모
		std::vector<int> denominatorVec;
		for (int i = 2; i <= m - n; i++)
		{
			denominatorVec.emplace_back(i);
		}

		bool check = true;
		int nIndex = 0;
		int dIndex = 0;
		while (check)
		{
			// 나눠 떨어진다면
			if (numeratorVec[nIndex] % denominatorVec[dIndex] == 0)
			{
				
			}
		}

		int a = 0;

		//unsigned long long denominator = factorial(m - n);

		//unsigned long long result = numerator / denominator;

		//unsigned long long numerator = factorial(m);

		// 분모
		//unsigned long long denominator = factorial(m - n) * factorial(n);

		//unsigned long long result = numerator / denominator;
		//std::cout << result << '\n';

		//std::vector<int> vec(n);
		//
		//for (int j = 0; j < n; j++)
		//{
		//	vec[j] = j;
		//}
		//
		//int count = 0;
		//Func(n, m, vec, count);
		//
		//std::cout << count << '\n';
	}

	return 0;
};