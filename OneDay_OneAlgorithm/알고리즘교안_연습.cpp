#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main2()
{
	/*
	int m1, m2;
	scanf("%d.%d", &m1, &m2);	// 3.22�� �Է¹��� ��

	// �Է��� ����ؼ� �־��� ��
	// �Է��� �ִٰ� ���� �� �����ٰ� ��õǾ��ִ� ���
	string n;
	while (cin >> n)
	{

	}

	/// ���
	// �Ǽ��� ���
	cout.precision(7);

	double a = 1.23456789;
	int b = 2;
	printf("%.6lf\n", a);
	printf("%02d\n", b);

	// ���ڸ� ���ڷ�
	char a = 'a';
	int intA = a - 'a';		// 0

	/// ���ڿ�
	string dopa = "amumu is best";
	if (dopa.find("amumu") != string::npos)
	{
		// "amumu"�� �ִ�!
	}

	dopa.substr(0, 3);	// amu
	reverse(dopa.begin(), dopa.end());

	// atoi(s.c_str())
	// ���� �Է¹��� ���ڿ��� ���ڶ�� 0, �װ� �ƴ϶�� ���ڸ� ��ȯ
	string s = "1";
	string s2 = "amumu";
	atoi(s.c_str());	// 1
	atoi(s2.c_str());	// 0

	// C++������ 0�̸� false, 0�� �ƴϸ� ��� true
	
	/// �ڷᱸ��
	pair<int, int> p;
	tuple<int, int, int> t;

	p = { 1, 2 };
	t = make_tuple(1, 2, 3);

	int a, b, c;
	tie(a, b) = p;
	tie(a, b, c) = t;

	// sort �Լ�
	
	// vector
	// vector�� find
	vector<int> v;
	std::vector<int>::iterator it = find(v.begin(), v.end(), 100);
	if (it == v.end())
	{
		// ��ã�Ҵ�!
	}

	vector<int> v(5, 100);	// ũ�� 5, 100���� ä��
	
	// Array
	*/
	// fill, memset
//  	vector<vector<int>> vv(5, vector<int>(5, 0));
//  	fill(&vv[0][0], &vv[0][0] + 5*25, 100);
// 
// 	for (auto it : vv)
// 	{
// 		for (int i = 0; i < it.size(); i++)
// 		{
// 			cout << it[i] << '\n';
// 		}
// 	}

	/*
	// map�� find �޼ҵ�� ã�� ���ϸ� end() ���ͷ����͸� ��ȯ�Ѵ�.
	std::unordered_map<string, int> umap;
	auto search = umap.find("test4");
	if (search == umap.end())
	{
		// ��ã��
	}

	// �ʿ� ��Ұ� �ִ��� �������� Ȯ���ϰ� �ʿ� �����͸� �Ҵ��Ϸ���
	map<int, int> mp;
	if (mp[1] == 0)
		mp[1] = 2;

	// map�� ����

	// queue
	queue<int> q;
	while (q.size())
	{
		q.front();
		q.pop();
	}

	// struct
	struct Point
	{
		int x, y, z;
		bool operator < (const Point& a) const
		{
			if (x == a.x)
			{
				if (y == a.x)
					return z < a.z;

				return y < a.y;
			}

			return x < a.x;
		}
	};
	*/

	//vector<int> a;
	//for (int i = 1; i <= 3; i++) a.push_back(i);
	//for (int i = 5; i <= 10; i++) a.push_back(i);
	//cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n";

	//vector<int> v = { 2,3,4,5,7 };

	//cout << *upper_bound(v.begin(), v.end(), 0) << '\n';


	string a = "abc";
	cout << atoi(a.c_str());
	
	pair<int, int> p;
	p = make_pair(1, 2);
	int aa, bb;
	tie(aa, bb) = p;

	cout << aa << " " << bb;

	vector<int> v;
	auto it = find(v.begin(), v.end(), 100);
	if (it == v.end())
	{
		// ��ã��!!
	}

	map<int, int> mm;
	auto itt = mm.find(100);
	if (itt == mm.end())
	{
		// ��ã��!!
		cout << "����!!";
	}

	if (mm[1000] == 1)
	{
		mm[1000] = 111;
	}

	struct Point
	{
		int x, y;
		bool operator < (const Point& a) const
		{
			if (x == a.x)
			{
				return y < a.y;
			}

			return x < a.x;	// �������� (���� ���� �տ�)
		}
	};

	// priority_queue�� ���� �ݴ�, ���� ��찡 ����������

	return 0;
}

// split
// ���ڿ��� ���ڿ��� �������� ������ �Լ�
vector<string> split(string input, string check)
{
	vector<string> ret;
	long long pos = 0;
	string token;
	while ((pos = input.find(check)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + check.length());
	}
	ret.push_back(input);
	return ret;
}

// �ִ� �����
int getMaxCommonNum(int a, int b)
{
	if (a == 0) return b;
	return getMaxCommonNum(b % a, a);
}

// �ּ� ����� ( a * b / �ִ�����(a, b) )
int lcm(int a, int b)
{
	return (a * b) / getMaxCommonNum(a, b);
}

// �����佺�׳׽��� ü
// 1 ~ 1000 ���� �� �Ҽ��� ��� ����ض�.
void eratos(int n)
{
	vector<bool> eraBool(n + 1);

	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == true)
			continue;

		for (int j = i * 2; j <= n; j += i)
		{
			eraBool[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == false)
			cout << i << '\n';
	}
}

// �����佺�׳׽���ü2
// 1 ~ 1000������ �Ҽ� ����ض�.
bool isPrime(int n)
{
	if (n <= 1)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}


// ���������� ��
// n(n+1) / 2

// �¼� ���ϱ�
// pow -> double�� int�� �� ��ȯ
// ������ ���ϱ�
// ���� ��������.

// lower_bound
// upper_bound

int main3()
{
	vector<int> v = { 1,2,3,4,5 };

	cout << lower_bound(v.begin(), v.end(), 4) - v.begin() << '\n';
	cout << upper_bound(v.begin(), v.end(), 4) - v.begin() << '\n';

	rotate(v.begin(), v.begin() + v.size() - 1, v.end());	// 2 3 4 5 1
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	cout << "\n\n";
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << sum;

	int maxNum = *max_element(v.begin(), v.end());
	int minNum = *min_element(v.begin(), v.end());

	// n ���� ��ȯ
	vector<int> jin;
	int n = 10;
	int b = 2;
	while (n > 1)
	{
		jin.push_back(n % b);
		n /= b;
	}
	if (n == 1) jin.push_back(1);
	reverse(jin.begin(), jin.end());

	cout << "\n\n";
	for (int i = 0; i < jin.size(); i++)
	{
		cout << jin[i];
	}

	return 0;
}

// 2���� �迭 ȸ��
// �������� 90�� ȸ��
void rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];
			temp[i][j] = key[m - j - 1][i];	// ���������� 90�� ȸ��
		}
	}
	key = temp;
}

// split
vector<string> split(string input, string check)
{
	vector<string> ret;
	long long pos = 0;
	string token;
	while ((pos = input.find(check)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + check.length());
	}
	ret.push_back(input);
	return ret;
}

// atoi(s.c_str())
string s = "12414";
cout << atoi(s.c_str());

// greater<int> ��������
// less<int> ��������

vector<int> v;
auto findRet = find(v.begin(), v.end(), 100);
if (findRet == v.end())
{
	// ��ã��!
}

// vector ����
vector<int> v(5, 100);

struct Point
{
	int x, y;

	bool operator < (const Point& a) const
	{
		if (x == a.x)
		{
			y < a.y;		// ��������
		}

		return x < a.x;
	}
};

// �׷���, priority_queue�� ���� �ݴ��̴�.
priority_queue<int, vector<int>, greater<int>> pq;	// ��������

// ��� �ð����⵵
// �ڷ� ����			����		Ž��		����		����
// �迭				O(1)	O(n)	O(n)	O(n)
// ����				O(n)	O(n)	O(1)	O(1)
// ť				O(n)	O(n)	O(1)	O(1)
// ���� ���� ����Ʈ	O(n)	O(n)	O(1)	O(1)
// �ؽ� ���̺�		O(1)	O(1)	O(1)	O(1)
// ���� Ž�� Ʈ��		O(logn)	O(logn)	O(logn)	O(logn)
// AVL Ʈ��			O(logn)	O(logn)	O(logn)	O(logn)
// ���� �� Ʈ��		O(logn)	O(logn)	O(logn)	O(logn)

// �־� �ð����⵵
// �ڷ� ����			����		Ž��		����		����

// ������ ����
// ���� : nPr = n! / (n-r)!
vector<int> vvv = { 1,2,3,4,5 };
do
{
	cout << vvv[0];
} while (next_permutation(vvv.begin(), vvv.end()));
// ���� : nCr = n! / r!(n-r)!
vector<int> combiV;
void Combi(int n, int r, int start)
{
	if (combiV.size() == r)
	{
		// logic
	}

	for (int i = start + 1; i < n; i++)
	{
		combiV.push_back(input[i]);
		Combi(n, r, i);
		combiV.pop_back();
	}
}

for (int i = 0; i < n; i++)
{
	for (int j = i + 1; j < n; j++)
	{
		for (int k = j + 1; k < n; k++)
		{

		}
	}
}

// �ִ�����, �ּҰ����
int maxCommonNum(int a, int b)
{
	if (a == 0) return b;

	return maxCommonNum(b % a, a);
}

// �ּ� ����� = a * b / �ִ�����(a, b)
int lcm(int a, int b)
{
	return a * b / maxCommonNum(a, b);
}

// �����佺�׳׽��� ü1
// �迭�� ���� 1000
void era(int n)
{
	vector<bool> eraBool(n + 1);

	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == true)
			continue;

		for (int j = i * 2; j <= n; j += i)
		{
			eraBool[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == false)
			cout << i << '\n';
	}
}

// �迭�� �ʹ� Ŭ �� (1000�� �̻�)
bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// ���������� ��
// n(n+1) / 2

// �¼� ���ϱ�
// pow ���, double���̴� �� ��ȯ
// ������ ���ϱ�
// sqrt ���, double���̴� �� ��ȯ

// lower_bound
// upper_bound
vector<int> vBound = { 1,2,3,4,5,6 };
cout << lower_bound(vBound.begin(), vBound.end(), 4) - vBound.begin();

// �ð����� �ݽð� ����ȸ��
vector<int> vv = { 1,2,3,4,5 };
rotate(vv.begin(), vv.begin() + 1, vv.end());	// 2. 3. 4. 5. 1
rotate(vv.begin(), vv.begin() + vv.size() - 1, vv.end())	// 5, 1, 2, 3, 4

// �迭�� ��
accumulate(vv.begin(), vv.end(), 0);

// �迭 �� ���� ū ���
int amx = *max_element(vv.begin(), vv.end());

// n���� ��ȯ
int n = 10;
int b = 2;
vector<int> ret;
while (n > 1)
{
	ret.push_back(n % b);
	n /= b;
}
if (n == 1) ret.push_back(1);
reverse(ret.begin(), ret.end());

// 2���� �迭 ȸ�� �Լ�
// �������� 90�� ȸ��
void Rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];
		}
	}
	key = temp;
	return;
}

// 08/24
#include <bits/stdc++.h>
using namespace std;

while (cin >> s)
{

}

cout.precision(7);	// �����κ�, �Ҽ��κ� ���ļ� 7�ڸ�, ������ �ڸ��� �ݿø���

vector<string> split(string input, string check)
{
	vector<string> ret;
	long long pos = 0;
	string token;
	while ((pos = input.find(check)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + check.length());
	}
	ret.push_back(input);
	return ret;
}

// atoi(s.c_str())
// ������ ��� 0, ������ ��� ���� ����

// tie(a, b) = pi

// less<int>() : ��������
// greater<int>() : ��������

struct Point
{
	int x, y;
	bool operator < (const Point& a) const
	{
		if (x == a.x)
		{
			return y < a.y;
		}
		return x < a.x;		// ��������, ���� ���� �տ�
	}
};

// �׷��� priority_queue�� ���� �ݴ��̴�. ���� ��쿡 ����������.
// priority_queue�� ���ͽ�Ʈ��, �׸��� � ���δ�.

// ����
// nPr = n! / (n-r)!

// ����
// nCr = n! / r!(n-r)!

// �ִ� �����
int gcd(int a, int b)
{
	if (a == 0) return b;	// �������
	return gcd(b % a, a);
}

// �ּ� �����
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// �����佺�׳׽��� ü1
void era(int n)
{
	vector<bool>era(n + 1);

	for (int i = 2; i <= n; i++)
	{
		if (era[i] == true)
			continue;

		for (int j = 2 * i; j <= n; j += i)
		{
			era[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (era[i] == false)
			cout << i << ' ';
	}
}

// �迭�� ũ�Ⱑ 1000�� �̻��� ���
bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// ���������� ��
// n(n+1) / 2

// �¼� ���ϱ� pow ��� double�� ��ȯ��
// ������ ���ϱ� sqrt ��� double�� ��ȯ��

// lower_bound, upper_bound
vector<int> v = { 1,2,3,4,4,5 };
lower_bound(v.begin(), v.end(), 4) - v.begin();	// 3
upper_bound(v.begin(), v.end(), 4) - v.begin();	// 5

lower_bound(v.begin(), v.end(), 9) - v.begin();	// 6
upper_bound(v.begin(), v.end(), 9) - v.begin();	// 6

// �ð� ���� ȸ��
rotate(v.begin(), v.begin() + 1, v.end());	// 2 3 4 4 5 1
rotate(v.begin(), v.begin() + v.size() - 1, v.end())	// 5 1 2 3 4 4

// �迭�� ��
int sum = accumulate(v.begin(), v.end(), 0);

// �迭 �� ���� ū ���
int max = *max_element(v.begin(), v.end());

// n ���� ��ȯ
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

// 2���� �迭 ȸ��
// �������� 90�� ȸ��
void rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];
		}
	}
	key = temp;
}

// 2022/08/25(��)
#include <bits/stdc++.h>

int m1, m2;
scanf("%d.%d", &m1, &m2);

while (cin >> n)
{

}

cout.precision(7);
printf("%02d", m);
printf("%.6lf", d);

// ����ȯ

// split
vector<string> split(string input, string check)
{
	vector<string> ret;
	long long pos;
	string token;
	while ((pos = input.find(check)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + check.length());
	}
	ret.push_back(input);
	return ret;
}

// atoi(s.c_str())
// �Է¹����� ���ڶ�� 0, �ƴ϶�� ���� ��ȯ

// �ڷ� ����
// tie(a, b) = pa

// sort
// greater<int>() : ��������
// less<int>() : ��������

// vector�� find
auto it = find(vector.begin(), vector.end(), 100);
if (it == vector.end())
{
	// ��ã��
}

// memcpy
int a[5];
int temp[5];
memcpy(temp, a, sizeof(a));

struct Point
{
	int x, y, z;
	bool operator < (const Point& a) const
	{
		if (x == a.x)
		{
			if (y == a.y)
			{
				return z < a.z;
			}

			return y < a.y;
		}

		return x < a.x;		// ��������, priority_queue�� �ݴ�. ����������
	}
};

priority_queue<int, vector<int>, greater<int>()> pq;	// ��������...
priority_queue<Point, vector<Point>> pq2;

// ����
// nPr = n! / (n-r)!
vector<int> v = { 1,2,3,4 };
do
{
	cout << v[0];
} while (next_permutation(v.begin(), v.end()));

// ����
// nCr = n! / r!(n-r)!
void Combi(int n, int r, int start, vector<int>& v)
{
	if (v.size() == r)
	{
		// ����
	}
	for (int i = start + 1; i < n; i++)
	{
		v.push_back(input[i]);
		Combi(n, r, i, v);
		v.pop_back();
	}
}

void main()
{
	Combi(5, 3, -1, v);
}

for (int i = 0; i < n; i++)
{
	for (int j = i + 1; j < n; j++)
	{
		for (int k = j + 1; k < n; k++)
		{

		}
	}
}

// �ִ�����
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// �����佺�׳׽��� ü
void era(int n)
{
	vector<bool> eraBool(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == true)
			continue;

		for (int j = 2 * i; j <= n; j += i)
		{
			eraBool[j] = true;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (eraBool[i] == false)
			cout << i;
	}
}

// �����佺 2
bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// ���������� ��
// n(n+1)/2

// pow -> double�� ��ȯ��
// sqrt -> double�� ��ȯ��

vector<int> v = { 1,2,2,3,4 };
lower_bound(v.begin(), v.end(), 2) - v.begin();	// 1
upper_bound(v.begin(), v.end(), 2) - v.begin();	// 3

// 5
// 5
// 5

// 0
// 0
// 0

// �ð���� ȸ��
rotate(v.begin(), v.begin() + 1, v.end());	// 2 2 3 4 1
rotate(v.begin(), v.begin() + v.size() - 1, v.end());	// 4 1 2 2 3

// �迭�� ��
int sum = accumulate(v.begin(), v.end(), 0);

// �ִ밪, �ּҰ�
int maxNum = *max_element(v.begin(), v.end());

// n���� ��ȯ
vector<int> ret;
int n = 100;
int b = 2;
while (n > 1)
{
	ret.push_back(n % b);
	n /= b;
}
if (n == 1) ret.push_back(1);
reverse(ret.begin(), ret.end());

// 2���� �迭 ȸ���ϴ� �Լ�
// �������� 90�� ȸ��
void Rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];
		}
	}
	key = temp;
}