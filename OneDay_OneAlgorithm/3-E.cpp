#include <bits/stdc++.h>
using namespace std;

int nn;
int att[3] = { 9, 3, 1 };
int ret = 987654321;

void func(vector<int> hp, int cnt)
{
	if (ret < cnt)
	{
		return;
	}

	int n = hp.size();
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = i;

	int tempMin = 987654321;
	vector<vector<int>> check;
	for (int i = 0; i < n; i++) v[i] = i;
	do
	{
		bool isAllDead = true;
		int tempSum = 0;
		vector<int> tempHp = hp;
		vector<int> nowC;
		for (int i = 0; i < n; i++)
		{
			tempHp[v[i]] -= att[i];
			tempSum += tempHp[v[i]];
			
			if (tempHp[v[i]] > 0)
			{
				nowC.push_back(tempHp[v[i]]);
				isAllDead = false;
			}
		}

		if (isAllDead)
		{
			ret = min(ret, cnt);
		}
		else
		{
			if (tempSum < tempMin)
			{
				tempMin = tempSum;
				check.clear();
				check.push_back(nowC);
			}
			else if (tempSum == tempMin)
			{
				check.push_back(nowC);
			}
		}

	} while (next_permutation(v.begin(), v.end()));

	for (vector<int> vv : check)
	{
		func(vv, cnt + 1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> nn;
	vector<int> hp(nn);
	int sum = 0;
	int attSum = 0;
	for (int i = 0; i < nn; i++)
	{
		cin >> hp[i];
		sum += hp[i];
		attSum += att[i];
	}

	//if (sum % attSum == 0)
	//	ret = sum / attSum;
	//else
	//	ret = sum / attSum + 1;

	//first(hp);
	func(hp, 1);
	std::cout << ret;
}