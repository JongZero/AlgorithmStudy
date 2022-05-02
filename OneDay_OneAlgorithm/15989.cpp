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

	// 일단, 1로는 무조건 만들 수 있다.

	// 7의 경우, 1111111
	//			2로 3개까지 묶을 수 있음 (2221)
	//			2 1개 일경우	211111, 31111
	//			2 2개 일경우	22111,	2311,	331
	//			2 3개 일경우	2221,	223
	//			

	return 0;
}