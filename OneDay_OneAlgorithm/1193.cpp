#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;

	// x가 몇 번째 대각선 배열에 속해있는지 알아내자
	int count = 1;

	// 시작번째
	int startNum = 1;

	// 다음 번째까지 범위
	int range = 0;

	while (true)
	{
		// 시작번째 ~ 시작번째 + 이 배열의 범위 안에 속한다면 탈출
		if (startNum <= x && x <= startNum + range)
		{
			break;
		}
		else
		{
			range = count;
			startNum = startNum + range;

			count++;
		}
	}

	// 대각선 분자 배열에서 내가 몇 번째인지
	int countInArray = x - startNum;

	// 인덱스
	int i = 0;

	// 분모
	int mo = 0;

	// 분자
	int ja = 0;

	// 첫 번째일 경우
	if (count == 1)
	{
		mo = 1;
		ja = 1;
	}
	// 짝수번째에 속한다면
	// 작은 숫자부터 -> 큰 숫자로 (1 / count ~ count)
	else if (count % 2 == 0)
	{
		// 분모
		mo = count;

		// 분자
		ja = 1;

		// 1번째부터만 구하면된다.
		if (countInArray > 0)
		{
			// 대각선 분자 배열에서 내가 있는 인덱스까지 구한다.
			for (int i = 0; i < countInArray; i++)
			{
				// 분자는 더하고
				ja++;

				// 분모는 뺀다.
				mo--;
			}
		}
	}
	// 홀수번째에 속한다면
	// 큰 숫자부터 -> 작은 숫자로 (count ~ 1 / count)
	else
	{
		// 분모
		mo = 1;

		// 분자
		ja = count;

		// 1번째부터만 구하면된다.
		if (countInArray > 0)
		{
			for (int i = 0; i < countInArray; i++)
			{
				// 분자는 빼고
				ja--;

				// 분모는 더한다.
				mo++;
			}
		}
	}

	// 출력
	cout << ja << "/" << mo;

	return 0;
}