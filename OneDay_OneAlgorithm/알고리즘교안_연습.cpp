#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main2()
{
	/*
	int m1, m2;
	scanf("%d.%d", &m1, &m2);	// 3.22를 입력받을 때

	// 입력이 계속해서 주어질 때
	// 입력을 주다가 안줄 때 끝난다고 명시되어있는 경우
	string n;
	while (cin >> n)
	{

	}

	/// 출력
	// 실수형 출력
	cout.precision(7);

	double a = 1.23456789;
	int b = 2;
	printf("%.6lf\n", a);
	printf("%02d\n", b);

	// 문자를 숫자로
	char a = 'a';
	int intA = a - 'a';		// 0

	/// 문자열
	string dopa = "amumu is best";
	if (dopa.find("amumu") != string::npos)
	{
		// "amumu"가 있다!
	}

	dopa.substr(0, 3);	// amu
	reverse(dopa.begin(), dopa.end());

	// atoi(s.c_str())
	// 만약 입력받은 문자열이 문자라면 0, 그게 아니라면 숫자를 반환
	string s = "1";
	string s2 = "amumu";
	atoi(s.c_str());	// 1
	atoi(s2.c_str());	// 0

	// C++에서는 0이면 false, 0이 아니면 모두 true
	
	/// 자료구조
	pair<int, int> p;
	tuple<int, int, int> t;

	p = { 1, 2 };
	t = make_tuple(1, 2, 3);

	int a, b, c;
	tie(a, b) = p;
	tie(a, b, c) = t;

	// sort 함수
	
	// vector
	// vector의 find
	vector<int> v;
	std::vector<int>::iterator it = find(v.begin(), v.end(), 100);
	if (it == v.end())
	{
		// 못찾았다!
	}

	vector<int> v(5, 100);	// 크기 5, 100으로 채움
	
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
	// map의 find 메소드는 찾지 못하면 end() 이터레이터를 반환한다.
	std::unordered_map<string, int> umap;
	auto search = umap.find("test4");
	if (search == umap.end())
	{
		// 못찾음
	}

	// 맵에 요소가 있는지 없는지를 확인하고 맵에 데이터를 할당하려면
	map<int, int> mp;
	if (mp[1] == 0)
		mp[1] = 2;

	// map을 쓰자

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
		// 못찾음!!
	}

	map<int, int> mm;
	auto itt = mm.find(100);
	if (itt == mm.end())
	{
		// 못찾음!!
		cout << "모샂음!!";
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

			return x < a.x;	// 오름차순 (작은 것이 앞에)
		}
	};

	// priority_queue는 위와 반대, 위의 경우가 내림차순임

	return 0;
}

// split
// 문자열을 문자열을 기준으로 나누는 함수
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

// 최대 공약수
int getMaxCommonNum(int a, int b)
{
	if (a == 0) return b;
	return getMaxCommonNum(b % a, a);
}

// 최소 공배수 ( a * b / 최대공약수(a, b) )
int lcm(int a, int b)
{
	return (a * b) / getMaxCommonNum(a, b);
}

// 에라토스테네스의 체
// 1 ~ 1000 까지 중 소수를 모두 출력해라.
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

// 에라토스테네스의체2
// 1 ~ 1000만까지 소수 출력해라.
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


// 등차수열의 합
// n(n+1) / 2

// 승수 구하기
// pow -> double을 int로 형 변환
// 제곱근 구하기
// 위와 마찬가지.

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

	// n 진법 변환
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

// 2차원 배열 회전
// 왼쪽으로 90도 회전
void rotate90(vector<vector<int>>& key)
{
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = key[j][m - i - 1];
			temp[i][j] = key[m - j - 1][i];	// 오른쪽으로 90도 회전
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

// greater<int> 내림차순
// less<int> 오름차순

vector<int> v;
auto findRet = find(v.begin(), v.end(), 100);
if (findRet == v.end())
{
	// 못찾음!
}

// vector 선언
vector<int> v(5, 100);

struct Point
{
	int x, y;

	bool operator < (const Point& a) const
	{
		if (x == a.x)
		{
			y < a.y;		// 오름차순
		}

		return x < a.x;
	}
};

// 그러나, priority_queue는 위와 반대이다.
priority_queue<int, vector<int>, greater<int>> pq;	// 오름차순

// 평균 시간복잡도
// 자료 구조			접근		탐색		삽입		삭제
// 배열				O(1)	O(n)	O(n)	O(n)
// 스택				O(n)	O(n)	O(1)	O(1)
// 큐				O(n)	O(n)	O(1)	O(1)
// 이중 연결 리스트	O(n)	O(n)	O(1)	O(1)
// 해시 테이블		O(1)	O(1)	O(1)	O(1)
// 이진 탐색 트리		O(logn)	O(logn)	O(logn)	O(logn)
// AVL 트리			O(logn)	O(logn)	O(logn)	O(logn)
// 레드 블랙 트리		O(logn)	O(logn)	O(logn)	O(logn)

// 최악 시간복잡도
// 자료 구조			접근		탐색		삽입		삭제

// 순열과 조합
// 순열 : nPr = n! / (n-r)!
vector<int> vvv = { 1,2,3,4,5 };
do
{
	cout << vvv[0];
} while (next_permutation(vvv.begin(), vvv.end()));
// 조합 : nCr = n! / r!(n-r)!
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

// 최대공약수, 최소공배수
int maxCommonNum(int a, int b)
{
	if (a == 0) return b;

	return maxCommonNum(b % a, a);
}

// 최소 공배수 = a * b / 최대공약수(a, b)
int lcm(int a, int b)
{
	return a * b / maxCommonNum(a, b);
}

// 에라토스테네스의 체1
// 배열의 길이 1000
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

// 배열이 너무 클 때 (1000만 이상)
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

// 등차수열의 합
// n(n+1) / 2

// 승수 구하기
// pow 사용, double형이니 형 변환
// 제곱근 구하기
// sqrt 사용, double형이니 형 변환

// lower_bound
// upper_bound
vector<int> vBound = { 1,2,3,4,5,6 };
cout << lower_bound(vBound.begin(), vBound.end(), 4) - vBound.begin();

// 시계방향과 반시계 방향회전
vector<int> vv = { 1,2,3,4,5 };
rotate(vv.begin(), vv.begin() + 1, vv.end());	// 2. 3. 4. 5. 1
rotate(vv.begin(), vv.begin() + vv.size() - 1, vv.end())	// 5, 1, 2, 3, 4

// 배열의 합
accumulate(vv.begin(), vv.end(), 0);

// 배열 중 가장 큰 요소
int amx = *max_element(vv.begin(), vv.end());

// n진법 변환
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

// 2차원 배열 회전 함수
// 왼쪽으로 90도 회전
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

cout.precision(7);	// 정수부분, 소수부분 합쳐서 7자리, 마지막 자리는 반올림됨

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
// 문자일 경우 0, 숫자일 경우 숫자 리턴

// tie(a, b) = pi

// less<int>() : 오름차순
// greater<int>() : 내림차순

struct Point
{
	int x, y;
	bool operator < (const Point& a) const
	{
		if (x == a.x)
		{
			return y < a.y;
		}
		return x < a.x;		// 오름차순, 작은 것이 앞에
	}
};

// 그러나 priority_queue는 위와 반대이다. 위의 경우에 내림차순임.
// priority_queue는 다익스트라, 그리디 등에 쓰인다.

// 순열
// nPr = n! / (n-r)!

// 조합
// nCr = n! / r!(n-r)!

// 최대 공약수
int gcd(int a, int b)
{
	if (a == 0) return b;	// 기저사례
	return gcd(b % a, a);
}

// 최소 공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// 에라토스테네스의 체1
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

// 배열의 크기가 1000만 이상일 경우
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

// 등차수열의 합
// n(n+1) / 2

// 승수 구하기 pow 사용 double형 반환됨
// 제곱근 구하기 sqrt 사용 double형 반환됨

// lower_bound, upper_bound
vector<int> v = { 1,2,3,4,4,5 };
lower_bound(v.begin(), v.end(), 4) - v.begin();	// 3
upper_bound(v.begin(), v.end(), 4) - v.begin();	// 5

lower_bound(v.begin(), v.end(), 9) - v.begin();	// 6
upper_bound(v.begin(), v.end(), 9) - v.begin();	// 6

// 시계 방향 회전
rotate(v.begin(), v.begin() + 1, v.end());	// 2 3 4 4 5 1
rotate(v.begin(), v.begin() + v.size() - 1, v.end())	// 5 1 2 3 4 4

// 배열의 합
int sum = accumulate(v.begin(), v.end(), 0);

// 배열 중 가장 큰 요소
int max = *max_element(v.begin(), v.end());

// n 진법 변환
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

// 2차원 배열 회전
// 왼쪽으로 90도 회전
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

// 2022/08/25(목)
#include <bits/stdc++.h>

int m1, m2;
scanf("%d.%d", &m1, &m2);

while (cin >> n)
{

}

cout.precision(7);
printf("%02d", m);
printf("%.6lf", d);

// 형변환

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
// 입력받은게 문자라면 0, 아니라면 숫자 반환

// 자료 구조
// tie(a, b) = pa

// sort
// greater<int>() : 내림차순
// less<int>() : 오름차순

// vector의 find
auto it = find(vector.begin(), vector.end(), 100);
if (it == vector.end())
{
	// 못찾음
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

		return x < a.x;		// 오름차순, priority_queue는 반대. 내림차순임
	}
};

priority_queue<int, vector<int>, greater<int>()> pq;	// 오름차순...
priority_queue<Point, vector<Point>> pq2;

// 순열
// nPr = n! / (n-r)!
vector<int> v = { 1,2,3,4 };
do
{
	cout << v[0];
} while (next_permutation(v.begin(), v.end()));

// 조합
// nCr = n! / r!(n-r)!
void Combi(int n, int r, int start, vector<int>& v)
{
	if (v.size() == r)
	{
		// 로직
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

// 최대공약수
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// 에라토스테네스의 체
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

// 에라토스 2
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

// 등차수열의 합
// n(n+1)/2

// pow -> double형 반환함
// sqrt -> double형 반환함

vector<int> v = { 1,2,2,3,4 };
lower_bound(v.begin(), v.end(), 2) - v.begin();	// 1
upper_bound(v.begin(), v.end(), 2) - v.begin();	// 3

// 5
// 5
// 5

// 0
// 0
// 0

// 시계방향 회전
rotate(v.begin(), v.begin() + 1, v.end());	// 2 2 3 4 1
rotate(v.begin(), v.begin() + v.size() - 1, v.end());	// 4 1 2 2 3

// 배열의 합
int sum = accumulate(v.begin(), v.end(), 0);

// 최대값, 최소값
int maxNum = *max_element(v.begin(), v.end());

// n진법 변환
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

// 2차원 배열 회전하는 함수
// 왼쪽으로 90도 회전
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