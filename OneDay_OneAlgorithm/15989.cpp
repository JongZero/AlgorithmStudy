#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	std::cin >> t;

	vector<int> inputVec;
	for (int i = 0; i < t; i++)
	{
		std::cin >> inputVec[i];
	}

	// �ϴ�, 1�δ� ������ ���� �� �ִ�.

	// 7�� ���, 1111111
	//			2�� 3������ ���� �� ���� (2221)
	//			2 1�� �ϰ��	211111, 31111
	//			2 2�� �ϰ��	22111,	2311,	331
	//			2 3�� �ϰ��	2221,	223
	//			

	return 0;
}