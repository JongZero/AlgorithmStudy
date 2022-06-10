#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	long long dpVec[36] = { 0, };
	dpVec[0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		long long temp = 0;
		int k = i - 1;
		for (int j = 0; j < i; j++, k--)
		{
			temp += dpVec[j] * dpVec[k];
		}
		dpVec[i] = temp;
	}

	cout << dpVec[n];

	return 0;
}