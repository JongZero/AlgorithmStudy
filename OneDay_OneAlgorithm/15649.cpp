#include <iostream>

// �� Ʈ��ŷ�� ���� ó������ ����
// https://cryptosalamander.tistory.com/54
// ��������
// �ڵ�� �����ѵ�, ���ذ� ��ƴ�

int g_N, g_M;
const int g_Max = 8;
int g_Array[g_Max] = { 0, };
bool g_Visited[g_Max] = { 0, };

void Func(int count)
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
		for (int i = 0; i < g_N; i++)
		{
			if (g_Visited[i] == false)
			{
				g_Visited[i] = true;
				g_Array[count] = i + 1;
				Func(count + 1);
				g_Visited[i] = false;
;			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� ���� ����
	std::cin >> g_N >> g_M;

	Func(0);

	return 0;
}