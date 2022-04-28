#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long s = 0;
	std::cin >> s;

	long long sum = 0;
	long long count = 0;
	for (int i = 1; i <= s; i++)
	{
		sum += i;
		count++;

		// 합이 s를 넘었다면, 여태까지 더한 것중에 하나만 빼면 s를 구할 수 있다.
		// ex) s = 5, 1+2+3 까지 했을 때 6이지만, 여태 더한 숫자 중 하나인 1을 빼면 5를 맞출 수 있음
		if (sum > s)
		{
			count--;
			break;
		}
		else if (sum == s)
		{
			break;
		}
	}

	std::cout << count;

	return 0;
}