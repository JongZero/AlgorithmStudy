#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<string> inputVec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> inputVec[i];
	}

	// 중복 제거
	sort(inputVec.begin(), inputVec.end());
	inputVec.erase(unique(inputVec.begin(), inputVec.end()), inputVec.end());

	n = inputVec.size();
	int checkCount = 0;		// 다른 단어의 접두어가 되는 지?
	for (int i = 0; i < n; i++)
	{
		string now = inputVec[i];

		for (int j = 0; j < n; j++)
		{
			if (now.size() >= inputVec[j].size())
				continue;

			string check = inputVec[j].substr(0, now.size());

			if (now == check)
			{
				checkCount++;
				break;
			}
		}
	}

	cout << n - checkCount;

	return 0;
}