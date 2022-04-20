#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 역은 10개
	const int Total = 10;

	// 최대
	int Max = 0;

	// 현재 사람 수
	int count = 0;
	for (int i = 0; i < Total; i++)
	{
		// 탄사람
		int in = 0;
		// 내린사람
		int out = 0;

		// 입력
		std::cin >> out >> in;

		// 내리고
		count -= out;
		// 타고
		count += in;

		// 최대값과 비교
		if (count > Max)
		{
			Max = count;
		}
	}

	std::cout << Max;

	return 0;
}
