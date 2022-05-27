#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	int k = 0;

	std::cin >> n;
	std::cin >> k;

	std::vector<int> inputVec;

	inputVec.resize(n);
	std::vector<int> dpVec(k + 1);
	dpVec[0] = 1;

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		for (int j = inputVec[i]; j <= k; j++)
		{
			dpVec[j] += dpVec[j - inputVec[i]];
		}
	}

	std::cout << dpVec[k];

	return 0;
}