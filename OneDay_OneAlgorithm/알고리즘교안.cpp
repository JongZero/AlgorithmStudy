#include <stdc++.h>
//#include<bits/stdc++.h> - 모든 표준 라이브러리가 포함된 헤더
using namespace std;

// 문제를 풀 때는 이상한 문제가 아니라면 int의 최대값으로 20억까지가 아닌 987654321 또는 1e9를 씁니다.
// 왜냐하면 이 INF를 기반으로 INF + INF라는 연산이 일어날 수도 있고 INF * 2 연산, 그리고 INF + 작은 수 연산이 일어날 때 오버플로를 방지할 수 있기 때문

// float보다 double을 쓰자.

/// 입력
int m1, m2;
scanf("%d.%d", &m1, &m2);	// 3.22를 입력받을 때

// 입력이 계속해서 이어질 때
// (문제가 입력을 주다가 안줄 때 끝난다고 명시되어있는 경우)
while (cin >> n)

/// 출력
// 실수형 출력
	// 만약 cout을 사용해 정수부분 + 소수부분 해서 6자리까지 출력한다면 어떻게 해야할까? (소수부분은 반올림)
	double a = 1.23456789;
	cout.precision(7);
	cout << a << "\n";	// 1.234568

	// printf의 경우
	double a = 1.23456789;
	int b = 2;
	printf("%.6lf\n", a);	// 1.234568
	printf("%02d\n", b);	// 02
	// lf => double, ld => long long

/// 형변환
	// 같은 타입끼리 연산을 하자. 예를 들어 double은 double끼리 나눠야 한다.
	// double과 int가 나눠진다면 어떻게 될까? double이 된다.
	// "형과 형을 똑같이 해주어야 한다."

	// 문자를 숫자로, 숫자를 문자로
		// 문자를 숫자로 바꿀 때
		char a = 'a';
		int aInt = (int)a - 'a';
	
/// 문자열
string dopa = "amumu is best";
int main()
{
	cout << dopa << "\n";

	if (dopa.find("amumu") != string::npos)
	{
		// string dopa에 amumu가 있다!
	}

	dopa.substr(0, 3);	// amu
	reverse(dopa.begin(), dopa.end());	// tseb si umuma
}

// split
// 문자열을 문자열을 기준으로 나누는 split 함수를 이렇게 만들어보자.
vector<string> split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

// atoi(s.c_str())
// 만약 입력받은 문자열이 문자라면 0을 반환하고 그게 아니라면 숫자를 반환하게 된다.
int main()
{
	string s = "1";
	string s2 = "amumu";
	cout << atoi(s.c_str()) << '\n';	// 1
	cout << atoi(s2.c_str()) << '\n';	// 0
}

// C++에서는 0이면 false, 0이 아닌 값들은 모두 true가 된다.
// bool b = 1,2,3,4... 모두 true 이다.

/// 자료구조
// pair과 tuple
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;

int main()
{
	pi = { 1, 2 };	// pair는 이렇게 또는 make_pair(1, 2)로 만들 수 있음
	tl = make_tuple(1, 2, 3);

	tie(a, b) = pi;		// a = 1, b = 2
	tie(a, b, c) = tl;	// a = 1, b = 2, c = 3

	// tie를 안 쓴다면
	a = pi.first;
	b = pi.second;

	a = get<0>(tl);
	a = get<1>(tl);
	a = get<2>(tl);
}

// sort() 함수
	sort(first, last, *커스텀비교함수)
	// last에 배열의 마지막요소가 아닌 그 "다음"의 위치를 넣어주어야 한다.
	// 다시 말하자면 크기가 5인 배열 a가 있을 때, a[0] + 5는 배열의 마지막 원소가 아니다. 마지막 원소는 a[0] + 4다.
	// 하지만 sort에는 sort( a[0] + a[0] + 5) 라고 해야 한다는 것이다.

	// 3번째 인자로는 커스텀 비교함수(선택)이 있다.
	// greater<int>() : 내림차순
	// less<int>() : 오름차순

// vector
	// vector의 find
	vector<int> v;
	auto a = find(v.begin(), v.end(), 100);
	if (a == v.end())
	{
		// 못찾았다!
	}

	// vector 선언
	vector<int> v(5, 100);	// 5크기의 vector를 선언하고 100으로 채웠다.

// Array
	// 정적배열. 연속된 메모리 공간이며 스택에 할당된다.

	// 마찬가지로 find 사용 가능
	int v[10];
	auto a = find(v, v + 10, 100);
	if (a == v + 10)
	{
		// 못찾았다!
	}

	// 정적 배열의 크기는 문제에서 필요한 "최대크기"로 선언해야 한다.

// 배열의 초기화 : fill과 memset
	// vector로 2차원 배열 매트릭스 만들기
	vector<vector<int>> checked;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	// fill로도 초기화할 수 있다.
	fill(v.begin(), v.end(), 0);

	int dp[10][10] = { {0,} };
	fill(dist, dist + MAX_N, 0);

	// fill을 사용한 2차원 배열 초기화
	fill(&arr[0][0], &arr[0][0] + n * m, k);	// 이런식으로 한번에 초기화 가능

// 배열의 복사 : memcpy
	// temp라는 배열에 a라는 배열의 모든 것이 담기는 것은 다음과 같다.
	int a[5];
	int temp[5];
	int main()
	{
		for (int i = 0; i < 5; i++)
			a[i] = i;

		memcpy(temp, a, sizeof(a));
	}

// 2차원 배열을 탐색할 때는 첫번째 차원 >> 2번째 차원순으로 탐색하는게 성능이 좋다.
// 이는 C++에서 캐시를 첫번째 차원을 기준으로 하기 때문에 캐시관련 효율성 때문에 탐색을 하더라도 순서를 지켜가며 해주는 것이다.
// ex.
	const int y = 3;
	const int x = 4;
	int a[y][x];

	// good
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << a[i][j] << '\n';
		}
	}

// map
	unordered_map<string, int> umap;
	umap["test"] = 4;	// 이렇게 넣자

	// map의 find 메소드는 찾지 못하면 end() 이터레이터를 반환한다.
	auto search = umap.find("test4");
	if (search != umap.end())
		// 찾음
	else
		// 못찾음

	// 맵에 요소가 있는지 없는지를 확인하고 맵에 데이터를 할당하려면
	map<int, int> mp;
	if (mp[1] == 0)
		mp[1] = 2;

	// 정렬이 필요로 하지 않은 문제에는 unordered_map을 써야 할 것같지만 제출해보면 시간초과가 나기도 한다.
	// 이는 가장 최악의 경우 O(N)이기 때문이다. 되도록 map을 쓰자.

// set, multiset
	// 둘 다 자동적으로 정렬됨
	// multiset은 중복되는 원소도 집어넣을 수 있음
	// multiset의 erase는 같은 값을 가진 모든 원소를 지움 ex. multiset = {1, 2, 3, 3, 3} -> erase(3) -> {1, 2}

// stack
	// "교차하지 않고"라는 문장이 나오면 스택을 사용할지 말지를 의심해봐야 한다.

// queue
	// 주로 BFS에 쓰인다.
	// 보통 아래와 같이 size()와 함께 쓰인다.
	int main()
	{
		queue<int> q;
		for (int i = 1; i <= 10; i++)
			q.push(i);

		while (q.size())
		{
			cout << q.front() << ' ';
			q.pop();
		}
	}

// struct(구조체)
	struct Point
	{
		int y, x;
		Point(int y, int x) : y(y), x(x) {}
		Point() { y = -1; x = -1; }
		bool operator < (const Point& a) const
		{
			if (x == a.x) return y < a.y;		// 2 순위는 y를 기반으로 비교 (오름차순) 작은게 앞에
			return x < a.x;						// 1 순위는 x를 기반으로 비교 (오름차순) 작은게 앞에
		}

		// Point 구조체를 담은 vector를 정렬, 즉 sort(v.begin(), v.end()) 식으로 한다면 미리 설정해놓은 정렬기준에 맞춰 정렬이 됨 (위 함수)

		// x,y,z일 때는?? x, y, z순으로 우선순위 주고 싶을 때
		// x는 오름차순, y는 내림차순, z는 오름차순일 경우
		int z;
		bool operator < (const Point& a) const
		{
			if (x == a.x)
			{
				if (y == a.y)
					return z < a.z;	// 오름차순

				return y > a.y;		// 내림차순
			}

			return x < a.x;			// 오름차순
		}
	};

//--------------------------------------------------------------------------------//
//----------------------------------- 8/20(토) -----------------------------------//
//--------------------------------------------------------------------------------//