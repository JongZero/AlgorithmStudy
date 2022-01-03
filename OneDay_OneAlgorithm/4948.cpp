#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int Min = 1;
	const int Max = 123456;

	int numbers[Max * 2 + 1] = { 0, };

	while (true)
	{
		int n = 0;
		cin >> n;

		// 0이 입력되면 종료
		if (n == 0)
		{
			break;
		}

		// 소수의 개수
		int count = 0;

		// 에라토스테네스의 체 활용
		// 숫자를 배열에 넣어놓는다.
		for (int i = 1; i <= 2 * n; i++)
		{
			numbers[i] = i;
		}

		for (int i = 2; i * i <= 2 * n; i++)
		{
			// 이미 에라토스테네스의 체로 걸러진 수라면 검사하지않고 넘어간다.
			if (numbers[i] == 1)
			{
				continue;
			}

			for (int j = i * i; j <= 2 * n; j += i)
			{
				numbers[j] = 1;
			}
		}

		// n보다크고 2n보다 작거나 같은 소수의 개수를 구한다.
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (numbers[i] > 1)
			{
				count++;
			}
		}

		// 카운트 출력
		std::cout << count << "\n";
	}

	return 0;
}