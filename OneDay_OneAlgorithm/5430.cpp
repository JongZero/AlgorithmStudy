#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <string.h>

const int MaxCharCount = 10000003;
char inputFunc[MaxCharCount];
char inputArray[MaxCharCount];

// �� �� or �� �ڸ� ������.
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

		// ���� �����Ϸ��� ����
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
				// 1�� �ڸ�
				case 0:
					num = 0;
					num += nowNum;
					break;
				// 10�� �ڸ�
				case 1:
					hund = num;
					num *= 10;
					num += nowNum;
					break;
				// 100�� �ڸ�
				case 2:
					num -= hund * 10;	// ���� 10�� �ڸ� ����
					num *= 10;			// 10�� �ڸ��߰�
					num += hund * 100;	// 100�� �ڸ��߰�
					num += nowNum;		// 1�� �ڸ��߰�
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
				// R�� ���� ������ R�� ������ ���̾ƴ϶�
				// bool�� üũ�� ����
				// r�� true�� ���� �ڿ��� pop, false�� ���� �տ��� pop
				rTrue ^= true;
			}
			else if (inputFunc[j] == 'D')
			{
				if (!Func_D(deq, rTrue))
				{
					// ����ִٸ� ����
					isError = true;
					break;
				}
			}
		}

		// ���
		if (isError)
		{
			std::cout << "error\n";
		}
		else
		{
			std::cout << '[';

			// �� ����
			if (rTrue == false)
			{
				while (deq.size() > 1)
				{
					std::cout << deq.front() << ',';
					deq.pop_front();
				}
			}
			// �� ����
			else
			{
				while (deq.size() > 1)
				{
					std::cout << deq.back() << ',';
					deq.pop_back();
				}
			}

			// ������ ���� ���
			if (!deq.empty())
			{
				std::cout << deq.front();
			}
			std::cout << "]\n";
		}
	}

	return 0;
}