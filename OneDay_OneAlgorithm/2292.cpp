#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	const int max = 1000000000;

	/// Mark 1 메모리 초과
	/*
	int* numbers = new int[n];

	// 1 먼저 초기화
	numbers[0] = 1;

	// 2 부터 규칙에 따름
	// 6 -> 12 -> 18

	// 1번방부터 i까지 몇 개의 방을 지나는지
	int howMany = 2;

	// 숫자 범위
	int range = 6;

	// 현재 숫자 카운트
	int nowCount = 0;

	for (int i = 1; i < n; i++)
	{
		if (nowCount >= range)
		{
			// 카운트 초기화
			nowCount = 0;

			// 숫자 범위 증가 (6씩)
			range += 6;

			// 방 한개씩 더 지나야함
			howMany++;

		}

		numbers[i] = howMany;

		nowCount++;
	}

	cout << numbers[n - 1];

	delete[] numbers;
	numbers = nullptr;
	*/

	/// Mark2
	// max까지 돌면서 자신이 어디에 속했는지 찾자
	// (배열에 미리 넣어놓는 것이 아니라)
	if (n == 1)
	{
		cout << 1;
	}
	else
	{
		// 시작 숫자
		int startNum = 2;
		// 숫자 범위
		int range = 6;
		// 몇 칸 가야하는지
		int howMany = 2;
		
		while (true)
		{
			if (startNum <= n && n < startNum + range)
			{
				n = howMany;
				break;
			}
			else
			{
				// 끝 숫자의 다음부터 시작 숫자
				startNum = startNum + range;

				// 범위는 6씩 증가
				range += 6;

				// 몇 칸 가야되는지는 1씩 증가
				howMany++;
			}
		}

		cout << n;
	}

	return 0;
}