#include <bits/stdc++.h>
using namespace std;

int n, num;

int calculate(char op, int n1, int n2)
{
	if (op == '*') return n1 * n2;
	if (op == '/') return n1 / n2;
	if (op == '+') return n1 + n2;
	if (op == '-') return n1 - n2;
}

bool calc(string oper, int idx, int ret, int cnt)
{
	if (oper.size() == 0 || cnt == idx)
	{
		if (ret == num) return true;
		return false;
	}
	
	if (calc(oper, idx + 1, calculate(oper[idx], ret, n), cnt)) return true;
	if (idx + 2 <= oper.size())
	{
		int temp = calculate(oper[idx + 1], n, n);
		if (calc(oper, idx + 2, calculate(oper[idx], ret, temp), cnt)) return true;
	}
	return false;
}

string s;
bool func(string oper, int cnt, int i)
{
	if (cnt <= 0)
	{
		if (oper.size() == 0)
		{
			cout << "oper없음\n";
		}
		else if (cnt > 1 && oper.size() == 1)
		{
			cout << "oper 1개\n";
		}
		if (calc(oper, 0, n, i - 1))
		{
			cout << oper << "에서 성공!\n";
			return true;
		}
		return false;
	}
	if (func(oper + "+", cnt - 1, i)) return true;
	//if (func(oper + "-", cnt - 1)) return true;
	//if (func(oper + "*", cnt - 1)) return true;
	if (func(oper + "/", cnt - 1, i)) return true;
	if (func(oper, cnt - 1, i)) return true;
	return false;
}

int solution(int N, int number) {
	int answer = -1;
	n = N;
	num = number;

	// i : n을 사용한 횟수
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
			s += to_string(N);
		int w = 1;

		if (func(string(), i - 1, i))
		{
			cout << i << "에서 성공!\n";
			answer = i;
			break;
		}

		s = "";
	}

	return answer;
}

void main()
{
	cout << "ANSWER : " << solution(3, 7);
}