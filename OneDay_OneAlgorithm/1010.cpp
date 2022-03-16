#include <iostream>
#include <vector>

// 1. 처음에 mCn 콤비네이션 문제인지 모르고 Func함수를 이용한 재귀함수로 풀려고 시도
// 2. 그 다음으로는 mCn 공식대로 팩토리얼 함수 만들어서 푸는데 값이 너무컸다.
// 3. 세번째로는 팩토리얼을 바로 구하는게 아니라 3! 이면 벡터에 3,2,1 넣어놓고 계속해서 분모/분자
//	  하는 방식으로 풀었더니 성공!

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

		if (n == m)
		{
			std::cout << 1 << '\n';
			continue;
		}
		
		// 분자
		std::vector<int> numeratorVec;
		for (int i = n + 1; i <= m; i++)
		{
			numeratorVec.emplace_back(i);
		}

		// 분모
		std::vector<int> denominatorVec;
		for (int i = 1; i <= m - n; i++)
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
				numeratorVec[nIndex] = numeratorVec[nIndex] / denominatorVec[dIndex];

				denominatorVec[dIndex] = 1;
			}

			dIndex++;

			if (dIndex >= denominatorVec.size())
			{
				dIndex = 0;
				nIndex++;

				if (nIndex >= numeratorVec.size())
				{
					check = false;
				}
			}
		}

		unsigned long long numerator = 1;
		for (int i = 0; i < numeratorVec.size(); i++)
		{
			numerator *= numeratorVec[i];
		}

		unsigned long long denominator = 1;
		for (int i = 0; i < denominatorVec.size(); i++)
		{
			denominator *= denominatorVec[i];
		}

		unsigned long long result = numerator / denominator;

		std::cout << result << '\n';
	}

	return 0;
};