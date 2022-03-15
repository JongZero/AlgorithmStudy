#include <iostream>
#include <vector>

// 백 트랙킹에 대해 처음으로 접함
// https://cryptosalamander.tistory.com/54
// 참고했음
// 코드는 간단한데, 이해가 어렵다

int g_N, g_M;
const int g_Max = 8;
int g_Array[g_Max] = { 0, };

void Func(int num, int count)
{
	if (count == g_M)
	{
		for (int i = 0; i < g_M; i++)
		{
			std::cout << g_Array[i] << " ";
		}

		std::cout << "\n";
	}
	else
	{
		for (int i = num; i < g_N; i++)
		{
			g_Array[count] = i + 1;
			Func(i, count + 1);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
	std::cin >> g_N >> g_M;

	Func(0, 0);

	return 0;
}