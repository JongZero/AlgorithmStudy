#include <iostream>
#include <vector>

// �� Ʈ��ŷ�� ���� ó������ ����
// https://cryptosalamander.tistory.com/54
// ��������
// �ڵ�� �����ѵ�, ���ذ� ��ƴ�

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

	// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
	std::cin >> g_N >> g_M;

	Func(0, 0);

	return 0;
}