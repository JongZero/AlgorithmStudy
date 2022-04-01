#include <iostream>
#include <string>
#include <math.h>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 시간 초과 버전
	/*
	int t = 0;
	std::cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		int mul = 1;
		char mulChar = '1';
		std::string mulStr = "";

		// 1의 자리만 계속 알고있고,
		// 1의 자리에 b번 만큼 a를 곱해주면 된다.
		// 스트링을 활용해 1의 자리만 저장해놓는다.
		for (int j = 0; j < b; j++)
		{
			// char to int
			mul = mulChar - '0';
			mul *= a;
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
		}

		// char to int
		int result = mulChar - '0';

		// 출력
		std::cout << result << '\n';
	}
	*/

	// 다음 버전
	// 제곱 활용 - 시간 초과
	/*
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		// b가 홀수인가?
		bool isOdd = false;
		if (b % 2 == 1)
			isOdd = true;

		b /= 2;		// 제곱할 것이기 때문에 b를 2로 나눠준다.

		int mul = 1;
		char mulChar = '1';
		std::string mulStr = "";

		// 1의 자리만 계속 알고있고,
		// 1의 자리에 b번 만큼 a를 곱해주면 된다.
		// 스트링을 활용해 1의 자리만 저장해놓는다.
		for (int j = 0; j < b; j++)
		{
			// char to int
			mul = mulChar - '0';
			mul *= a;
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
		}

		// 맨 마지막 자리수만 필요
		mul = mulChar - '0';

		mul *= mul;	// 제곱
		
		// 홀수라면 한번 더 곱해준다.
		if (isOdd)
			mul *= a;

		// 마찬가지로 맨 마지막 자리수만 필요
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
			
		// char to int
		int result = mulChar - '0';

		if (result == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			// 출력
			std::cout << result << '\n';
		}
		
	}
	*/

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		int mul = a;
		char mulChar = '1';
		std::string mulStr = "";
		
		while (b >= 1)
		{	
			// 제곱
			// char to int
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
			mul = mulChar - '0';
			mul *= mul;

			// 제곱했으므로 지수는 계속 2로 나눠줌
			b /= 2;
		}

		// 마지막 자리수만 남긴다.
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		int result = mulChar - '0';

		if (result == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			// 출력
			std::cout << result << '\n';
		}
	}

	return 0;
}