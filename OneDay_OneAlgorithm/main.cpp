#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	set<int> s;
	multiset<int> ss;

	s.insert(5);
	s.insert(2);
	s.insert(6);
	s.insert(1);

	for (auto it : s)
	{
		cout << it << '\n';
	}

	return 0;
}