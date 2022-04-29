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

	

	return 0;
}