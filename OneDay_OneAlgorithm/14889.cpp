#include <iostream>
#include <vector>

std::vector<std::vector<int>> abilityVec;



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// �ɷ�ġ �Է� �ޱ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> abilityVec[i][j];
		}
	}
	
	// �� ���� ����
	int teamNum = n / 2;

	// n�� 4��� teamNum�� 2,
	// n�� ������ ¦��
	//	 1 2 3 4
	// 1 0 1 5 1
	// 2 3 0 9 1
	// 3 5 5 0 2
	// 4 8 5 5 0

	return 0;
}