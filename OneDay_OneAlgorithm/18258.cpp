#include <iostream>
#include <string>

const int MaxQueue = 2000001;
int g_QueueData[MaxQueue] = { 0, };
int g_FrontIndex = 0;
int g_RearIndex = 0;
int g_Size = 0;

void push(int x)
{
	// rear에 push
	g_QueueData[g_RearIndex] = x;
	g_RearIndex++;
	g_Size++;
}

bool empty()
{
	return (g_Size <= 0);
}

int pop()
{
	if (!empty())
	{
		// front에서 pop
		int popNum = g_QueueData[g_FrontIndex];
		g_QueueData[g_FrontIndex] = 0;
		g_FrontIndex++;
		g_Size--;
		return popNum;
	}
	else
	{
		return -1;
	}
}

// 가장 앞에 있는 정수 출력
// 큐에 아무것도 없으면 -1 출력
int front()
{
	if (!empty())
	{
		return g_QueueData[g_FrontIndex];
	}
	else
	{
		return -1;
	}
}

// 가장 뒤에 있는 정수 출력
// 큐에 아무것도 없으면 -1 출력
int back()
{
	if (!empty())
	{
		return g_QueueData[g_RearIndex - 1];
	}
	else
	{
		return -1;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		// 들어온 명령이 push일 경우
		if (0 == input.compare("push"))
		{
			// x도 추가적으로 input을 받는다.
			int inputX = 0;
			std::cin >> inputX;

			push(inputX);
		}
		else if (0 == input.compare("pop"))
		{
			std::cout << pop() << '\n';
		}
		else if (0 == input.compare("size"))
		{
			std::cout << g_Size << '\n';
		}
		else if (0 == input.compare("empty"))
		{
			std::cout << empty() << '\n';
		}
		else if (0 == input.compare("front"))
		{
			std::cout << front() << '\n';
		}
		else if (0 == input.compare("back"))
		{
			std::cout << back() << '\n';
		}
	}

	return 0;
}