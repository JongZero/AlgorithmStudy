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

