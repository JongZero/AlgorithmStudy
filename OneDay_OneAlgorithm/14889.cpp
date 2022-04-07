#include <iostream>
#include <vector>

std::vector<std::vector<int>> abilityVec;



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// 능력치 입력 받기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> abilityVec[i][j];
		}
	}
	
	// 한 팀의 숫자
	int teamNum = n / 2;

	

	return 0;
}