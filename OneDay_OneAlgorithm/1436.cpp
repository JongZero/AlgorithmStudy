#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// 666
	// 1666
	// 2666
	// 3666
	// 4666
	// 5666
	// 6660
	// 6661
	// 6662
	// 6663
	// 6664
	// 6665
	// 6666
	// 6667
	// 6668
	// 6669
	// 7666
	// 8666
	// 9666
	// 10666
	// 11666
	// 12666
	// 13666
	// 14666
	// 15666
	// 16660
	// 16661
	// 16662
	// 16663
	// 16664
	// 16665
	// 16666
	// 16667
	// 16668
	// 16669
	// 17666
	// 18666
	// 19666
	// 20666
	
	int count = 1;
	int now = 666;
	while (true)
	{
		if (count == n)
			break;

		now++;

		string str = to_string(now);

		// 숫자에 666이 있다면
		if (str.find("666") != string::npos)
		{
			// 카운트 증가
			count++;
		}
	}

	cout << now;

	return 0;
}