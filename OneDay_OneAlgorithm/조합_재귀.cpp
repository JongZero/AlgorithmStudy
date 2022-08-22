#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> input = { 1, 2, 3, 4, 5 };
vector<int> v;
void Func(int n, int r, int nowI)
{
	if (v.size() == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = nowI + 1; i < n; i++)
	{
		v.push_back(input[i]);
		Func(n, r, i);
		v.pop_back();
	}
}

int main()
{
	int n = 5;
	int r = 3;

	Func(n, r, -1);
}