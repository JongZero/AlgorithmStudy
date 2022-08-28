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

