#include <stdc++.h>
#include <unordered_map>
using namespace std;

int main()
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

	vector<int> v = { 2,3,4,5,7 };

	cout << *upper_bound(v.begin(), v.end(), 0) << '\n';

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
