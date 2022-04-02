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

	// 정답 버전
	// 아이디어 : 최소한의 계산 횟수를 먼저 구하고, 계산한다. (지수법칙활용)
	// ex) 2의 100제곱 (계산 횟수 : 100번)
	// 2의 100제곱 = 2의 제곱의 50제곱 (51번 = 제곱 1번 + 50제곱 50번)
	// 2의 제곱의 50제곱 = 2의 제곱의 제곱의 25제곱 (27번 = 제곱 2번 + 25제곱 25번)
	// 2의 제곱의 제곱의 25제곱 = 2의 제곱의 제곱의 제곱의 12제곱 * 2의 4제곱 (19번 = 제곱 3번 + 12제곱 12번 + 나머지 4번)
	// 이런식으로 계산 횟수가 최소가 되는 것을 구해서 그에 맞는 계산을 해준다.
	// 말로 설명하기가 어렵다...
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		// 몇 번 제곱을 해줄지 카운트
		int bCount = 0;

		// bCount만큼 제곱을 하고나서 남는 숫자,
		// a의 remainderCount제곱을 구할 것이다.
		int remainder = 1;
		int remainderCount = 0;

		// 계산 횟수
		int prev = 1000000;
		int now = 0;

		while (true)
		{
			if (b < 2)
			{
				break;
			}

			// 홀수라면 나머지가 생긴다. (나머지는 2의 이전의 제곱 횟수 제곱)
			if (b % 2 == 1)
			{
				remainderCount += remainder;
			}

			int prevB = b;
			b /= 2;
			bCount++;
			remainder = pow(2, bCount);

			now = bCount + b + remainderCount;

			// 현재 횟수가 이전의 횟수보다 많다면
			// 이전의 횟수가 최소 횟수임
			if (now > prev)
			{
				b = prevB;
				bCount--;
				remainderCount -= pow(2, bCount);
				break;
			}

			prev = now;
		}

		/// 제곱부터 해준다.
		int mul = a;
		char mulChar = '1';
		std::string mulStr = "";
		for (int j = 0; j < bCount; j++)
		{
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			mul = mulChar - '0';
			mul *= mul;
		}

		/// b번만큼 mul을 제곱
		// 맨 마지막 자리수만 필요
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';
		int bResult = mul;
		for (int j = 0; j < b - 1; j++)
		{
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			mul = mulChar - '0';
			mul *= bResult;
		}

		// 맨 마지막 자리수만 필요
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';

		/// 나머지 계산 (a의 remainderCount 제곱)
		int remainderResult = 1;
		for (int j = 0; j < remainderCount; j++)
		{
			mulStr = std::to_string(remainderResult);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			remainderResult = mulChar - '0';
			remainderResult *= a;
		}
		
		// 둘이 합친다.
		mul *= remainderResult;

		// 맨 마지막 자리수를 마지막으로 구한다.
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';

		// 0이면 10번 컴퓨터
		if (mul == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			std::cout << mul << '\n';
		}
	}

	return 0;
}