#include <iostream>
#include <vector>

// �� Ʈ��ŷ�� ���� ó������ ����
// https://cryptosalamander.tistory.com/54
// ��������
// �ڵ�� �����ѵ�, ���ذ� ��ƴ�

int g_N, g_M;
const int g_Max = 8;
int g_Array[g_Max] = { 0, };
bool g_Visited[g_Max] = { 0, };
std::vector<std::vector<int>> g_NumsVec;

void Func(int count)
{
	if (count == g_M)
	{
		// �ߺ� üũ
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
			// �ߺ� �ƴ϶�� ��� + �ߺ�üũ ���Ϳ� �ֱ�
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

	// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
	std::cin >> g_N >> g_M;

	Func(0);

	return 0;
}