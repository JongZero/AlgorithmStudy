#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <string.h>

const int MaxCharCount = 10000003;
char inputFunc[MaxCharCount];
char inputArray[MaxCharCount];

// 맨 앞 or 맨 뒤를 버린다.
bool Func_D(std::deque<int>& deq, const bool& rTrue)
{
	if (deq.empty())
	{
		return false;
	}
	else
	{
		if (rTrue)
		{
			deq.pop_back();
		}
		else
		{
			deq.pop_front();
		}
		return true;
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
		std::cin >> inputFunc;

		int arrayCount = 0;
		std::cin >> arrayCount;

		std::deque<int> deq;
		std::cin >> inputArray;

		// 현재 저장하려는 숫자
		int num = -1;
		int hund = 0;
		int numCount = 0;
		int size = strlen(inputArray);
		for (int j = 0; j < size; j++)
		{
			if (inputArray[j] >= '0' && inputArray[j] <= '9')
			{
				int nowNum = inputArray[j] - '0';

				switch (numCount)
				{
				// 1의 자리
				case 0:
					num = 0;
					num += nowNum;
					break;
				// 10의 자리
				case 1:
					hund = num;
					num *= 10;
					num += nowNum;
					break;
				// 100의 자리
				case 2:
					num -= hund * 10;	// 기존 10의 자리 제거
					num *= 10;			// 10의 자리추가
					num += hund * 100;	// 100의 자리추가
					num += nowNum;		// 1의 자리추가
					break;
				}

				numCount++;
			}
			else if (inputArray[j] == ',' || inputArray[j] == ']')
			{
				numCount = 0;

				if (num > 0)
				{
					deq.push_back(num);
					num = 0;
					hund = 0;
				}
			}
		}

		bool rTrue = false;
		bool isError = false;
		size = strlen(inputFunc);
		for (int j = 0; j < size; j++)
		{
			if (inputFunc[j] == 'R')
			{
				// R이 들어올 때마다 R을 뒤집는 것이아니라
				// bool로 체크만 해줌
				// r이 true일 때는 뒤에서 pop, false일 때는 앞에서 pop
				rTrue ^= true;
			}
			else if (inputFunc[j] == 'D')
			{
				if (!Func_D(deq, rTrue))
				{
					// 비어있다면 에러
					isError = true;
					break;
				}
			}
		}

		// 출력
		if (isError)
		{
			std::cout << "error\n";
		}
		else
		{
			std::cout << '[';

			// 정 방향
			if (rTrue == false)
			{
				while (deq.size() > 1)
				{
					std::cout << deq.front() << ',';
					deq.pop_front();
				}
			}
			// 역 방향
			else
			{
				while (deq.size() > 1)
				{
					std::cout << deq.back() << ',';
					deq.pop_back();
				}
			}

			// 마지막 숫자 출력
			if (!deq.empty())
			{
				std::cout << deq.front();
			}
			std::cout << "]\n";
		}
	}

	return 0;
}