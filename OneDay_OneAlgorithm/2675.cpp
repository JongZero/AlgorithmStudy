#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t;

	cin >> t;

	vector<int> rVec;
	vector<string> sVec;

	for (int k = 0; k < t; k++)
	{
		int r;

		cin >> r;

		rVec.push_back(r);

		string s;

		cin >> s;

		sVec.push_back(s);
	}
	
	for (int k = 0; k < t; k++)
	{
		for (int i = 0; i < sVec[k].size(); i++)
		{
			for (int j = 0; j < rVec[k]; j++)
			{
				cout << sVec[k][i];
			}
		}

		cout << "\n";
	}

	return 0;
}