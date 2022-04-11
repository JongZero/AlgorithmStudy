#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		std::cin >> n;

		int index = 0;
		while (true)
		{
			// 2로 나눈 나머지를 구함
			int remainder = n % 2;

			// 1의 위치 출력
			if (remainder == 1)
			{
				std::cout << index << ' ';
			}

			// index 증가, 2로 나눠줌
			index++;
			n /= 2;

			// 더 이상 나눌 수 없으면 끝
			if (n < 1)
			{
				break;
			}
		}
	}

	return 0;
}