#include <bits/stdc++.h>
using namespace std;

// int�� �ִ����� 20������� �ƴ� 987654321 �Ǵ� 1e9�� ����.
// �ֳ��ϸ� �� INF�� ������� INF + INF��� ������ �Ͼ �� �� �ְ�
// INF * 2 ����, �׸��� INF + ���� �� ������ �Ͼ �� �����÷θ� ������ �� �ֱ� ����.

// float ���ٴ� double

int m1, m2;
scanf("%d.%d", &m1, &m2);

cout.precision(7);

printf("%.6lf", d);
printf("%02d", i);

// ����ȯ
// ���� ���� �Ȱ��� ���ְ� ���ϰų� ������.

// split
vector<string> split(string input, string check)
{
	vector<string> ret;
	string token;
	long long pos = 0;
	while ((pos = input.find(check)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + check.length());
	}
	ret.push_back(input);
	return ret;
}

// atoi(s.c_str())	// ������ ��� 0�� ��ȯ�Ѵ�.

memcpy(temp, a, sizeof(a));

// ���������ʰ�, ¦����, ���� -> stack

// queue
	// �ַ� BFS
	// size()

struct Point
{
	int y, x;
	bool operator < (const Point& a) const
	{
		if (x == a.x) return y < a.y;	// 2������ y�� �������, ��������
		return x < a.x;		// 1������ x�� �������, ��������
	}
};

// ������ ����
// ����
// nPr = n! / (n-r)!
// ����
// nCr = n! / r!(n-r)!

vector<int> input;
vector<int> now;
void Combi(int n, int r, int start)
{
	if (now.size() == r)
	{
		// ����
	}
	for (int i = start + 1; i < n; i++)
	{
		now.push_back(input[i]);
		Combi(n, r, start);
		now.pop_back();
	}
}

// ��ø for��
for (int i = 0; i < n; i++)
{
	for (int j = i + 1; j < n; j++)
	{

	}
}

// �ִ�����
int gcd(int a, int b)
{
	if (a == 0) return b;
	gcd(b % a, a);
}

// �ּҰ����
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// �����佺�׳׽��� ü
void era(int n)
{
	vector<bool> che(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (che[i] == true) continue;
		for (int j = 2 * i; j <= n; j += i)
		{
			che[j] = true;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (che[i] == false) cout << i << '\n';
	}
}

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

// ���������� ��
// n(n+1) / 2

// �¼�, ������ ���ϱ�
// pow, sqrt, double�� ��ȯ��

// lower_bound, upper_bound
vector<int> v = { 1,2,3,3,7 };

*lower_bound(v.begin(), v.end(), 3);	// 2

rotate(v.begin(), v.begin() + 1, v.end()); // 2 3 3 7 1
retate(v.begin(), v.begin() + v.size() - 1, v.end());	// 7 1 2 3 3

int sum = accumulate(v.begin(), v.end(), 0);
int maxNum = *max_element(v.begin(), v.end());

// n���� ��ȯ
int n = 100;
int b = 2;
vector<int> ret;
while (n > 1)
{
	ret.push_back(n % b);
	n /= b;
}
if (n == 1) ret.push_back(1);
reverse(ret.begin(), ret.end());

void rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];

			temp[i][j] = key[m - j - 1][i];
		}
	}
	key = temp;
}
