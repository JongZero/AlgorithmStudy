#include <stdc++.h>
#include <unordered_map>
using namespace std;

int main()
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

	vector<int> v = { 2,3,4,5,7 };

	cout << *upper_bound(v.begin(), v.end(), 0) << '\n';

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
