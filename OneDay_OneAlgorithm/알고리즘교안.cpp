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
	// 하지만 sort에는 sort( a[0], a[0] + 5 ) 라고 해야 한다는 것이다.

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

// priority queue
	// 내부구조는 heap으로 구현되어있으며 주로 다익스트라, 그리디 등에 쓰인다.
	priority_queue<int, vector<int>, greater<int>> pq;	// 오름차순

	struct Point
	{
		int x, y;
		bool operator < (const Point& a) const
		{
			return x < a.x;		// sort함수의 커스텀 정렬과 다르게, 우선순위큐는 반대다. 이 경우 내림차순이다. 즉 가장 큰 것이 root이다.
		}
	};

// 자료구조 시간복잡도 정리
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
	// 자료구조			접근		탐색		삽입		삭제
	// 배열				O(1)	O(n)	O(n)	O(n)
	// 스택				O(n)	O(n)	O(1)	O(1)
	// 큐				O(n)	O(n)	O(1)	O(1)
	// 이중 연결 리스트	O(n)	O(n)	O(1)	O(1)
	// 해시 테이블		O(n)	O(n)	O(n)	O(n)
	// 이진 탐색 트리		O(n)	O(n)	O(n)	O(n)
	// AVL 트리			O(logn)	O(logn)	O(logn)	O(logn)
	// 레드 블랙 트리		O(logn)	O(logn)	O(logn)	O(logn)

/// 수학
// 순열과 조합
// 경우의 수라고 했을 때 기본적으로 순열과 조합이 생각나야 한다!

// 순열
	// permutation, 순서가 정해진 임의의 집합을 다른 순서로 섞는 연산을 말한다.
	// 1,2,3 이렇게 있을 때 1,3,2 이런식으로 다른 순서로 섞는 연산을 순열이라 한다.
	// n개의 집합 중 n개를 고르는 순열의 개수는 n!
	// nPr = n! / (n-r)!

	// 코드로는 어떻게?
	// next_permutation(오름차순), prev_permutation(내림차순)
	int a[3] = { 1,2,3 };

	vector<int> v = { 1,2,3 };

	do
	{
		printV(v);
	} while (next_permutation(v.begin(), v.end()));

	// 일부만 넣을 수도 있다.
	next_permutation(v.begin(), v.begin() + 2);	// 배열의 0, 1 순서만을 고치게 된다.

// 조합
	// 조합에서 "순서"는 없다. 그저 몇명을 뽑아서 갈 것인가를 쓸 때 조합을 쓴다.
	// 순서따윈 상관없고 오로지 몇명을 "다양하게" 뽑을 때 사용하는 것이다.
	// nCr = n! / r!(n-r)!
	// 예를 들어 5개 중에 3개를 뽑는다고 하면 5! / 3! * 2! = 10
	
	// 코드로 구현
	// 재귀
	int n = 5, k = 3, a[5] = { 1,2,3,4,5 };
	void combi(int start, vector<int> b)
	{
		if (b.size() == k)
		{
			print(b);
			return;
		}
		for (int i = start + 1; i < n; i++)
		{
			b.push_back(i);
			combi(i, b);
			b.pop_back();
		}
		return;
	}
	int main()
	{
		vector<int> b;
		combi(-1, b);
	}

	// 중첩 for문
	// r이 작을 때는 이렇게 구현
	// r이 3개이면 3중 for문
	int main()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					std::cout << i << " " << j << " " << k << '\n';
				}
			}
		}
	}

/// 정수론
// 최대공약수와 최소공배수
// 최대공약수
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

// 최소 공배수
// lcm은 (a*b / (a와 b의 최소공배수))
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

// 에라토스테네스의 체
vector<int> era(int mx_n)
{
	vector<int> v;
	vector<bool> che(mx_n);
	for (int i = 2; i <= mx_n; i++)
	{
		if (che[i] == true) continue;
		for (int j = 2 * i; j <= mx_n; j += i)
		{
			che[j] = true;
		}
	}
	for (int i = 2; i <= mx_n; i++)
	{
		if (che[i] == false)
			v.push_back(i);
	}
	return v;
}
// 위는 배열의 크기가 필요, 배열의 크기가 일정 수준(1000만 이상)을 벗어나면 쓰기가 힘듬
// 이럴 때는 일일히 소수를 판별하는 bool 함수 필요
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
// 기본적으로 1씩 증가하는 수열의 경우 n(n+1) / 2 이다. 
// 예를 들어, n이 3이면 3 * 4 / 2 = 6이다. 1 + 2 + 3 = 6이기 때문

// 승수 구하기
// pow 사용, pow는 double형을 받고 double형을 리턴하기 때문에 int로 사용하고 싶다면 형변환을 해주자.
int n = 4;
int pow_2 = (int)pow(2, n);

// 제곱근 구하기
// 승수 구하기와 마찬가지로 int로 사용하고 싶다면 형변환을 해주자.
int n = 16;
int ret = (int)sqrt(n);

/// 질문으로 배우는 코딩테스트에 자주나오는 필수로직
// lower_bound와 upper_bound
	vector<int> v = { 2,3,4,5,7 };

	*lower_bound(v.begin(), v.end(), 5);	// 5, 인덱스로는 3
	*upper_bound(v.begin(), v.end(), 5);	// 7, 인덱스로는 4
	
	// (인덱스 구하기)
	lower_bound(v.begin(), v.end(), 5) - v.begin();

	// 배열에 없는 숫자인 경우?
	lower_bound(v.begin(), v.end(), 6);		// 7, 인덱스로는 4
	upper_bound(v.begin(), v.end(), 6);		// 7, 인덱스로는 4

	lower_bound(v.begin(), v.end(), 10);	// 인덱스 바깥이라 값은 못구함, 인덱스로는 5
	upper_bound(v.begin(), v.end(), 10);	// 인덱스 바깥이라 값은 못구함, 인덱스로는 5

	lower_bound(v.begin(), v.end(), 0);		// 2, 인덱스로는 0
	upper_bound(v.begin(), v.end(), 0);		// 2, 인덱스로는 0

// 시계방향과 반시계방향 회전
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	// 앞으로 할 땐 이렇게
	rotate(v.begin(), v.begin() + 1, v.end());	// 2 3 4 5 6 7 8 9 1

	// 뒤로 할 땐 이렇게
	rotate(v.begin(), v.begin() + v.size() - 1, v.end());	// 9 1 2 3 4 5 6 7 8

// 배열의 합
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = accumulate(v.begin(), v.end(), 0);
	// 위에서 0은 초기값. 즉 0에다가 v의 원소들을 더하는 것임
	// 10을 넣으면 10 + v 원소들의 합

// 배열 중 가장 큰 요소, max_element
	int maxNum = *max_element(v.begin(), v.end());
	int minNum = *min_element(v.begin(), v.end());

// n진법 변환
	// 어떤 숫자 n에서 b진법으로 바꾸는 방법은?
	vector<int> v;
	int main()
	{
		int n = 100;
		int b = 2;	// 2진법
		while (n > 1)
		{
			v.push_back(n % b);
			n /= b;
		}
		if (n == 1) v.push_back(1);
		reverse(v.begin(), v.end());
	}

// 2차원 배열을 회전하는 함수
	// 2차원 배열을 90도 회전시키는 함수를 구현해라.
	// 왼쪽으로 90도
	void rotate90(vector<vector<int>>& key)
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

	// 오른쪽으로 90도
	void rotate90(vector<vector<int>>& key)
	{
		int m = key.size();
		vector<vector<int>> temp(m, vector<int>(m, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = key[m - j - 1][i];
			}
		}
		key = temp;
		return;
	}

/// 코드를 구축하는 법
// 전역변수를 사용하자. 0으로 초기화되기 때문에 예상 가능

// 외워야 할 숫자
	// 시간복잡도를 어림잡아 계산할 때 자주 나오는 수들. 이정도는 외워주자.
	// 10! = 3628800
	// 2^10 = 1024
	// 3^10 = 59049

// 실수형 연산
	// 부동소수점 소수표현은 언제나 제한된 정확도를 가지게 된다.