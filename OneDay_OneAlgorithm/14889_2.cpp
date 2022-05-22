#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pairIndex;
vector<bool> isVisited;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	isVisited.resize(n);

	unordered_map<pairIndex, int> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;

			if (input != 0)
				m[make_pair(i, j)] = input;
		}
	}



	return 0;
}