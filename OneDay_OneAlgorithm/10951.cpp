#include <iostream>
using namespace std;

// 이 문제의 입력 설명에는 "입력의 끝은 0 0 으로 주어진다"같은 문구가 없으며,
// "첫 번째 줄에 테스트 케이스의 개수 T가 주어진다"같은 문구도 없습니다.
// 즉, 이 문제에서 입력의 마지막을 알기 위해서는 더 이상 입력이 없음(End of file, EOF)를 파악하는 방법이 유일한 방법입니다.

int main()
{
	while (true)
	{
		int a = 0, b = 0;

		cin >> a >> b;

		if (cin.eof())
			break;

		cout << a + b << endl;
	}

	return 0;
}