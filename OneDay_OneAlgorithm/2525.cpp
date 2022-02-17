#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a, b, c;
	std::cin >> a >> b >> c;

	b += c;

	// 60분이 넘었다면
	if (b >= 60)
	{
		while (true)
		{
			// 60분이 안넘을 때까지 추가
			if (b < 60)
			{
				break;
			}

			// 1시간 추가
			a += 1;

			// 60분씩 빼줌
			b -= 60;
		}
	}
	
	// 24시가 넘었다면
	if (a >= 24)
	{
		// 0부터 다시 시작
		a -= 24;
	}

	std::cout << a << " " << b;

	return 0;
}