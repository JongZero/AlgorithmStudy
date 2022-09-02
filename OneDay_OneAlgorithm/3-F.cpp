#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll ret = -22087654321;
int s[19];
int tempS[19];
int visited[19];
int a[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };

enum
{
	PLUS = 10,
	MINUS = 11,
	MULTI = 12,
};

void Calc()
{
	ll tempRet = tempS[0];
	int prev = -1;
	for (int i = 1; i < n; i++)
	{
		int c = tempS[i];
		if (c == PLUS || c == MINUS || c == MULTI)
		{
			prev = c;
		}
		else
		{
			if (prev == PLUS)
			{
				tempRet += c;
			}
			else if (prev == MINUS)
			{
				tempRet -= c;
			}
			else if (prev == MULTI)
			{
				tempRet *= c;
			}
		}
	}
	if (ret < tempRet)
		ret = tempRet;
}

vector<int> now;
void combi(int start, int r)
{
	if (now.size() == r)
	{
		memcpy(tempS, s, sizeof(s));
		for (int ii : now)
		{
			//cout << ii << ' ';
			int temp = 0;
			int c = tempS[ii];
			if (c == PLUS)
			{
				//cout << "PLUS\n";
				temp += (tempS[ii - 1] + tempS[ii + 1]);
			}
			else if (c == MINUS)
			{
				//cout << "MINUS\n";
				temp += (tempS[ii - 1] - tempS[ii + 1]);
			}
			else
			{
				//cout << "MULTI\n";
				temp += (tempS[ii - 1] * tempS[ii + 1]);
			}
			tempS[ii - 1] = temp;
			tempS[ii] = PLUS;
			tempS[ii + 1] = 0;
		}
		Calc();
		//cout << "\n";
		return;
	}
	for (int i = start; i < n; i ++)
	{
		if (s[i] == PLUS || s[i] == MINUS || s[i] == MULTI)
		{
			if (visited[i]) continue;
			now.push_back(i);
			visited[i] = 1;
			visited[i + 2] = 1;
			combi(i, r);
			now.pop_back();
			visited[i] = 0;
			visited[i + 2] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	ret = -22087654321;

	cin >> n;
	string input;
	cin >> input;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		char c = input[i];
		if (c == '+')
		{
			s[i] = PLUS;
			cnt++;
		}
		else if (c == '-')
		{
			s[i] = MINUS;
			cnt++;
		}
		else if (c == '*')
		{
			s[i] = MULTI;
			cnt++;
		}
		else
		{
			s[i] = c - '0';
		}
	}
	memcpy(tempS, s, sizeof(s));
	Calc();

	for (int i = cnt; i >= 1; i--)
	{
		combi(-1, i);
	}
	cout << ret;

	//ll a = 1;
	//for (int i = 0; i < 10; i++)
	//{
	//	a *= 9;
	//}
	//cout << a;
	// 연산자 최대 9개

	// 2 -> 3 (연산자의 개수 - 1?)
	// 1 -> 4 (연산자의 개수)
}