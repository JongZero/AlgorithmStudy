#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> pairIndex;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	map<pairIndex, int> m;
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

	// n / 2¸¸Å­ »Ì´Â´Ù.
	// 4 -> 2, 6 -> 3
	vector<int> nVec(n);
	for (int i = n / 2; i < n; i++)
	{
		nVec[i] = 1;
	}

	int min = 100000000;
	do 
	{
		vector<int> choiceVec;
		vector<int> notChoiceVec;

		// ÆÀÀ» »Ì´Â´Ù.
		for (int i = 0; i < n; i++)
		{
			if (nVec[i] == 1)
				choiceVec.push_back(i);
			else
				notChoiceVec.push_back(i);
		}

		int choiceAbility = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				choiceAbility += m[pairIndex(choiceVec[i], choiceVec[j])];
			}
		}

		int notChoiceAbility = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				notChoiceAbility += m[pairIndex(notChoiceVec[i], notChoiceVec[j])];
			}
		}

		int sub = abs(notChoiceAbility - choiceAbility);
		if (min > sub)
			min = sub;

	} while (next_permutation(nVec.begin(), nVec.end()));

	cout << min;

	return 0;
}