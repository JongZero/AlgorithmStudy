#include <bits/stdc++.h>
using namespace std;

// int의 최댓값으로 20억까지가 아닌 987654321 또는 1e9를 쓰자.
// 왜냐하면 이 INF를 기반으로 INF + INF라는 연산이 일어날 수 도 있고
// INF * 2 연산, 그리고 INF + 작은 수 연산이 일어날 때 오버플로를 방지할 수 있기 때문.

// float 보다는 double

int m1, m2;
scanf("%d.%d", &m1, &m2);

cout.precision(7);

printf("%.6lf", d);
printf("%02d", i);

// 형변환
// 형과 형을 똑같이 해주고 곱하거나 나누자.

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

// atoi(s.c_str())	// 문자인 경우 0을 반환한다.

memcpy(temp, a, sizeof(a));

// 교차하지않고, 짝짓기, 폭발 -> stack

// queue
	// 주로 BFS
	// size()

struct Point
{
	int y, x;
	bool operator < (const Point& a) const
	{
		if (x == a.x) return y < a.y;	// 2순위를 y를 기반으로, 오름차순
		return x < a.x;		// 1순위는 x를 기반으로, 오름차순
	}
};

// 순열과 조합
// 순열
// nPr = n! / (n-r)!
// 조합
// nCr = n! / r!(n-r)!

vector<int> input;
vector<int> now;
void Combi(int n, int r, int start)
{
	if (now.size() == r)
	{
		// 로직
	}
	for (int i = start + 1; i < n; i++)
	{
		now.push_back(input[i]);
		Combi(n, r, start);
		now.pop_back();
	}
}

// 중첩 for문
for (int i = 0; i < n; i++)
{
	for (int j = i + 1; j < n; j++)
	{

	}
}

// 최대공약수
int gcd(int a, int b)
{
	if (a == 0) return b;
	gcd(b % a, a);
}

// 최소공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// 에라토스테네스의 체
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

// 등차수열의 합
// n(n+1) / 2

// 승수, 제곱근 구하기
// pow, sqrt, double형 반환함

// lower_bound, upper_bound
vector<int> v = { 1,2,3,3,7 };

*lower_bound(v.begin(), v.end(), 3);	// 2

rotate(v.begin(), v.begin() + 1, v.end()); // 2 3 3 7 1
retate(v.begin(), v.begin() + v.size() - 1, v.end());	// 7 1 2 3 3

int sum = accumulate(v.begin(), v.end(), 0);
int maxNum = *max_element(v.begin(), v.end());

// n진법 변환
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
