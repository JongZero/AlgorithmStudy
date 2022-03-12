#include <iostream>
#include <vector>

// 백 트랙킹에 대해 처음으로 접함
// https://cryptosalamander.tistory.com/54
// 참고했음
// 코드는 간단한데, 이해가 어렵다

int g_N, g_M;
const int g_Max = 8;
int g_Array[g_Max] = { 0, };
bool g_Visited[g_Max] = { 0, };
std::vector<std::vector<int>> g_NumsVec;

void Func(int count)
{
	if (count == g_M)
	{
		// 중복 체크
		bool check = false;
		int checkCount = 0;
		for (int i = 0; i < g_NumsVec.size(); i++)
		{
			for (int j = 0; j < g_NumsVec[i].size(); j++)
			{
				for (int k = 0; k < g_M; k++)
				{
					int a = g_NumsVec[i][j];

					if (g_Array[k] == a)
					{
						checkCount++;
					}

					if (checkCount >= g_M)
					{
						check = true;
						break;
					}
				}

				if (check)
					break;
			}

			checkCount = 0;

			if (check)
				break;
		}

		if (check == false)
		{
			// 중복 아니라면 출력 + 중복체크 벡터에 넣기
			std::vector<int> nums;
			for (int i = 0; i < g_M; i++)
			{
				std::cout << g_Array[i] << " ";
				nums.push_back(g_Array[i]);
			}

			g_NumsVec.push_back(nums);
			std::cout << "\n";
		}
	}
	else
	{
		for (int i = 0; i < g_N; i++)
		{
			if (g_Visited[i] == false)
			{
				g_Visited[i] = true;
				g_Array[count] = i + 1;
				Func(count + 1);
				g_Visited[i] = false;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
	std::cin >> g_N >> g_M;

	Func(0);

	return 0;
}