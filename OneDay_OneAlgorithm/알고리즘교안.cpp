#include <stdc++.h>
//#include<bits/stdc++.h> - ��� ǥ�� ���̺귯���� ���Ե� ���
using namespace std;

// ������ Ǯ ���� �̻��� ������ �ƴ϶�� int�� �ִ밪���� 20������� �ƴ� 987654321 �Ǵ� 1e9�� ���ϴ�.
// �ֳ��ϸ� �� INF�� ������� INF + INF��� ������ �Ͼ ���� �ְ� INF * 2 ����, �׸��� INF + ���� �� ������ �Ͼ �� �����÷θ� ������ �� �ֱ� ����

// float���� double�� ����.

/// �Է�
int m1, m2;
scanf("%d.%d", &m1, &m2);	// 3.22�� �Է¹��� ��

// �Է��� ����ؼ� �̾��� ��
// (������ �Է��� �ִٰ� ���� �� �����ٰ� ��õǾ��ִ� ���)
while (cin >> n)

/// ���
// �Ǽ��� ���
	// ���� cout�� ����� �����κ� + �Ҽ��κ� �ؼ� 6�ڸ����� ����Ѵٸ� ��� �ؾ��ұ�? (�Ҽ��κ��� �ݿø�)
	double a = 1.23456789;
	cout.precision(7);
	cout << a << "\n";	// 1.234568

	// printf�� ���
	double a = 1.23456789;
	int b = 2;
	printf("%.6lf\n", a);	// 1.234568
	printf("%02d\n", b);	// 02
	// lf => double, ld => long long

/// ����ȯ
	// ���� Ÿ�Գ��� ������ ����. ���� ��� double�� double���� ������ �Ѵ�.
	// double�� int�� �������ٸ� ��� �ɱ�? double�� �ȴ�.
	// "���� ���� �Ȱ��� ���־�� �Ѵ�."

	// ���ڸ� ���ڷ�, ���ڸ� ���ڷ�
		// ���ڸ� ���ڷ� �ٲ� ��
		char a = 'a';
		int aInt = (int)a - 'a';
	
/// ���ڿ�
string dopa = "amumu is best";
int main()
{
	cout << dopa << "\n";

	if (dopa.find("amumu") != string::npos)
	{
		// string dopa�� amumu�� �ִ�!
	}

	dopa.substr(0, 3);	// amu
	reverse(dopa.begin(), dopa.end());	// tseb si umuma
}

// split
// ���ڿ��� ���ڿ��� �������� ������ split �Լ��� �̷��� ������.
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
// ���� �Է¹��� ���ڿ��� ���ڶ�� 0�� ��ȯ�ϰ� �װ� �ƴ϶�� ���ڸ� ��ȯ�ϰ� �ȴ�.
int main()
{
	string s = "1";
	string s2 = "amumu";
	cout << atoi(s.c_str()) << '\n';	// 1
	cout << atoi(s2.c_str()) << '\n';	// 0
}

// C++������ 0�̸� false, 0�� �ƴ� ������ ��� true�� �ȴ�.
// bool b = 1,2,3,4... ��� true �̴�.

/// �ڷᱸ��
// pair�� tuple
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;

int main()
{
	pi = { 1, 2 };	// pair�� �̷��� �Ǵ� make_pair(1, 2)�� ���� �� ����
	tl = make_tuple(1, 2, 3);

	tie(a, b) = pi;		// a = 1, b = 2
	tie(a, b, c) = tl;	// a = 1, b = 2, c = 3

	// tie�� �� ���ٸ�
	a = pi.first;
	b = pi.second;

	a = get<0>(tl);
	a = get<1>(tl);
	a = get<2>(tl);
}

// sort() �Լ�
	sort(first, last, *Ŀ���Һ��Լ�)
	// last�� �迭�� ��������Ұ� �ƴ� �� "����"�� ��ġ�� �־��־�� �Ѵ�.
	// �ٽ� �����ڸ� ũ�Ⱑ 5�� �迭 a�� ���� ��, a[0] + 5�� �迭�� ������ ���Ұ� �ƴϴ�. ������ ���Ҵ� a[0] + 4��.
	// ������ sort���� sort( a[0], a[0] + 5 ) ��� �ؾ� �Ѵٴ� ���̴�.

	// 3��° ���ڷδ� Ŀ���� ���Լ�(����)�� �ִ�.
	// greater<int>() : ��������
	// less<int>() : ��������

// vector
	// vector�� find
	vector<int> v;
	auto a = find(v.begin(), v.end(), 100);
	if (a == v.end())
	{
		// ��ã�Ҵ�!
	}

	// vector ����
	vector<int> v(5, 100);	// 5ũ���� vector�� �����ϰ� 100���� ä����.

// Array
	// �����迭. ���ӵ� �޸� �����̸� ���ÿ� �Ҵ�ȴ�.

	// ���������� find ��� ����
	int v[10];
	auto a = find(v, v + 10, 100);
	if (a == v + 10)
	{
		// ��ã�Ҵ�!
	}

	// ���� �迭�� ũ��� �������� �ʿ��� "�ִ�ũ��"�� �����ؾ� �Ѵ�.

// �迭�� �ʱ�ȭ : fill�� memset
	// vector�� 2���� �迭 ��Ʈ���� �����
	vector<vector<int>> checked;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	// fill�ε� �ʱ�ȭ�� �� �ִ�.
	fill(v.begin(), v.end(), 0);

	int dp[10][10] = { {0,} };
	fill(dist, dist + MAX_N, 0);

	// fill�� ����� 2���� �迭 �ʱ�ȭ
	fill(&arr[0][0], &arr[0][0] + n * m, k);	// �̷������� �ѹ��� �ʱ�ȭ ����

// �迭�� ���� : memcpy
	// temp��� �迭�� a��� �迭�� ��� ���� ���� ���� ������ ����.
	int a[5];
	int temp[5];
	int main()
	{
		for (int i = 0; i < 5; i++)
			a[i] = i;

		memcpy(temp, a, sizeof(a));
	}

// 2���� �迭�� Ž���� ���� ù��° ���� >> 2��° ���������� Ž���ϴ°� ������ ����.
// �̴� C++���� ĳ�ø� ù��° ������ �������� �ϱ� ������ ĳ�ð��� ȿ���� ������ Ž���� �ϴ��� ������ ���Ѱ��� ���ִ� ���̴�.
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
	umap["test"] = 4;	// �̷��� ����

	// map�� find �޼ҵ�� ã�� ���ϸ� end() ���ͷ����͸� ��ȯ�Ѵ�.
	auto search = umap.find("test4");
	if (search != umap.end())
		// ã��
	else
		// ��ã��

	// �ʿ� ��Ұ� �ִ��� �������� Ȯ���ϰ� �ʿ� �����͸� �Ҵ��Ϸ���
	map<int, int> mp;
	if (mp[1] == 0)
		mp[1] = 2;

	// ������ �ʿ�� ���� ���� �������� unordered_map�� ��� �� �Ͱ����� �����غ��� �ð��ʰ��� ���⵵ �Ѵ�.
	// �̴� ���� �־��� ��� O(N)�̱� �����̴�. �ǵ��� map�� ����.

// set, multiset
	// �� �� �ڵ������� ���ĵ�
	// multiset�� �ߺ��Ǵ� ���ҵ� ������� �� ����
	// multiset�� erase�� ���� ���� ���� ��� ���Ҹ� ���� ex. multiset = {1, 2, 3, 3, 3} -> erase(3) -> {1, 2}

// stack
	// "�������� �ʰ�"��� ������ ������ ������ ������� ������ �ǽ��غ��� �Ѵ�.

// queue
	// �ַ� BFS�� ���δ�.
	// ���� �Ʒ��� ���� size()�� �Բ� ���δ�.
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

// struct(����ü)
	struct Point
	{
		int y, x;
		Point(int y, int x) : y(y), x(x) {}
		Point() { y = -1; x = -1; }
		bool operator < (const Point& a) const
		{
			if (x == a.x) return y < a.y;		// 2 ������ y�� ������� �� (��������) ������ �տ�
			return x < a.x;						// 1 ������ x�� ������� �� (��������) ������ �տ�
		}

		// Point ����ü�� ���� vector�� ����, �� sort(v.begin(), v.end()) ������ �Ѵٸ� �̸� �����س��� ���ı��ؿ� ���� ������ �� (�� �Լ�)

		// x,y,z�� ����?? x, y, z������ �켱���� �ְ� ���� ��
		// x�� ��������, y�� ��������, z�� ���������� ���
		int z;
		bool operator < (const Point& a) const
		{
			if (x == a.x)
			{
				if (y == a.y)
					return z < a.z;	// ��������

				return y > a.y;		// ��������
			}

			return x < a.x;			// ��������
		}
	};

//--------------------------------------------------------------------------------//
//----------------------------------- 8/20(��) -----------------------------------//
//--------------------------------------------------------------------------------//

// priority queue
	// ���α����� heap���� �����Ǿ������� �ַ� ���ͽ�Ʈ��, �׸��� � ���δ�.
	priority_queue<int, vector<int>, greater<int>> pq;	// ��������

	struct Point
	{
		int x, y;
		bool operator < (const Point& a) const
		{
			return x < a.x;		// sort�Լ��� Ŀ���� ���İ� �ٸ���, �켱����ť�� �ݴ��. �� ��� ���������̴�. �� ���� ū ���� root�̴�.
		}
	};

// �ڷᱸ�� �ð����⵵ ����
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
	// �ڷᱸ��			����		Ž��		����		����
	// �迭				O(1)	O(n)	O(n)	O(n)
	// ����				O(n)	O(n)	O(1)	O(1)
	// ť				O(n)	O(n)	O(1)	O(1)
	// ���� ���� ����Ʈ	O(n)	O(n)	O(1)	O(1)
	// �ؽ� ���̺�		O(n)	O(n)	O(n)	O(n)
	// ���� Ž�� Ʈ��		O(n)	O(n)	O(n)	O(n)
	// AVL Ʈ��			O(logn)	O(logn)	O(logn)	O(logn)
	// ���� �� Ʈ��		O(logn)	O(logn)	O(logn)	O(logn)

/// ����
// ������ ����
// ����� ����� ���� �� �⺻������ ������ ������ �������� �Ѵ�!

// ����
	// permutation, ������ ������ ������ ������ �ٸ� ������ ���� ������ ���Ѵ�.
	// 1,2,3 �̷��� ���� �� 1,3,2 �̷������� �ٸ� ������ ���� ������ �����̶� �Ѵ�.
	// n���� ���� �� n���� ���� ������ ������ n!
	// nPr = n! / (n-r)!

	// �ڵ�δ� ���?
	// next_permutation(��������), prev_permutation(��������)
	int a[3] = { 1,2,3 };

	vector<int> v = { 1,2,3 };

	do
	{
		printV(v);
	} while (next_permutation(v.begin(), v.end()));

	// �Ϻθ� ���� ���� �ִ�.
	next_permutation(v.begin(), v.begin() + 2);	// �迭�� 0, 1 �������� ��ġ�� �ȴ�.

// ����
	// ���տ��� "����"�� ����. ���� ����� �̾Ƽ� �� ���ΰ��� �� �� ������ ����.
	// �������� ������� ������ ����� "�پ��ϰ�" ���� �� ����ϴ� ���̴�.
	// nCr = n! / r!(n-r)!
	// ���� ��� 5�� �߿� 3���� �̴´ٰ� �ϸ� 5! / 3! * 2! = 10
	
	// �ڵ�� ����
	// ���
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

	// ��ø for��
	// r�� ���� ���� �̷��� ����
	// r�� 3���̸� 3�� for��
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

/// ������
// �ִ������� �ּҰ����
// �ִ�����
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

// �ּ� �����
// lcm�� (a*b / (a�� b�� �ּҰ����))
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

// �����佺�׳׽��� ü
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
// ���� �迭�� ũ�Ⱑ �ʿ�, �迭�� ũ�Ⱑ ���� ����(1000�� �̻�)�� ����� ���Ⱑ ����
// �̷� ���� ������ �Ҽ��� �Ǻ��ϴ� bool �Լ� �ʿ�
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
// �⺻������ 1�� �����ϴ� ������ ��� n(n+1) / 2 �̴�. 
// ���� ���, n�� 3�̸� 3 * 4 / 2 = 6�̴�. 1 + 2 + 3 = 6�̱� ����

// �¼� ���ϱ�
// pow ���, pow�� double���� �ް� double���� �����ϱ� ������ int�� ����ϰ� �ʹٸ� ����ȯ�� ������.
int n = 4;
int pow_2 = (int)pow(2, n);

// ������ ���ϱ�
// �¼� ���ϱ�� ���������� int�� ����ϰ� �ʹٸ� ����ȯ�� ������.
int n = 16;
int ret = (int)sqrt(n);

/// �������� ���� �ڵ��׽�Ʈ�� ���ֳ����� �ʼ�����
// lower_bound�� upper_bound
	vector<int> v = { 2,3,4,5,7 };

	*lower_bound(v.begin(), v.end(), 5);	// 5, �ε����δ� 3
	*upper_bound(v.begin(), v.end(), 5);	// 7, �ε����δ� 4
	
	// (�ε��� ���ϱ�)
	lower_bound(v.begin(), v.end(), 5) - v.begin();

	// �迭�� ���� ������ ���?
	lower_bound(v.begin(), v.end(), 6);		// 7, �ε����δ� 4
	upper_bound(v.begin(), v.end(), 6);		// 7, �ε����δ� 4

	lower_bound(v.begin(), v.end(), 10);	// �ε��� �ٱ��̶� ���� ������, �ε����δ� 5
	upper_bound(v.begin(), v.end(), 10);	// �ε��� �ٱ��̶� ���� ������, �ε����δ� 5

	lower_bound(v.begin(), v.end(), 0);		// 2, �ε����δ� 0
	upper_bound(v.begin(), v.end(), 0);		// 2, �ε����δ� 0

// �ð����� �ݽð���� ȸ��
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	// ������ �� �� �̷���
	rotate(v.begin(), v.begin() + 1, v.end());	// 2 3 4 5 6 7 8 9 1

	// �ڷ� �� �� �̷���
	rotate(v.begin(), v.begin() + v.size() - 1, v.end());	// 9 1 2 3 4 5 6 7 8

// �迭�� ��
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = accumulate(v.begin(), v.end(), 0);
	// ������ 0�� �ʱⰪ. �� 0���ٰ� v�� ���ҵ��� ���ϴ� ����
	// 10�� ������ 10 + v ���ҵ��� ��

// �迭 �� ���� ū ���, max_element
	int maxNum = *max_element(v.begin(), v.end());
	int minNum = *min_element(v.begin(), v.end());

// n���� ��ȯ
	// � ���� n���� b�������� �ٲٴ� �����?
	vector<int> v;
	int main()
	{
		int n = 100;
		int b = 2;	// 2����
		while (n > 1)
		{
			v.push_back(n % b);
			n /= b;
		}
		if (n == 1) v.push_back(1);
		reverse(v.begin(), v.end());
	}

// 2���� �迭�� ȸ���ϴ� �Լ�
	// 2���� �迭�� 90�� ȸ����Ű�� �Լ��� �����ض�.
	// �������� 90��
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

	// ���������� 90��
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

/// �ڵ带 �����ϴ� ��
// ���������� �������. 0���� �ʱ�ȭ�Ǳ� ������ ���� ����

// �ܿ��� �� ����
	// �ð����⵵�� ���� ����� �� ���� ������ ����. �������� �ܿ�����.
	// 10! = 3628800
	// 2^10 = 1024
	// 3^10 = 59049

// �Ǽ��� ����
	// �ε��Ҽ��� �Ҽ�ǥ���� ������ ���ѵ� ��Ȯ���� ������ �ȴ�.