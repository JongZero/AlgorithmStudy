#include <iostream>
#include <string>
using namespace std;

string Switching(string s, int size);

int main()
{
	string a, b, output;
	cin >> a >> b;

	// 사이즈 비교
	int sizeA = a.size();
	int sizeB = b.size();

	string biggerNumberStr;		// 더 큰 숫자 스트링

	int lesserSize = 0;			// 더 큰 사이즈
	int biggerSize = 0;			// 더 작은 사이즈
	if (sizeA > sizeB)
	{
		lesserSize = sizeB;
		biggerSize = sizeA;

		biggerNumberStr = a;
	}
	else
	{
		lesserSize = sizeA;
		biggerSize = sizeB;

		biggerNumberStr = b;
	}

	// 스위칭 한다. 앞 뒤를 바꾼다.
	a = Switching(a, sizeA);
	b = Switching(b, sizeB);
	biggerNumberStr = Switching(biggerNumberStr, biggerNumberStr.size());

	// 10이 넘었는지 (넘었다면 다음 자리에 +1 해줘야함)
	bool isOver = false;

	// a, b 중에 작은 자리수의 끝까지 계속 더해준다.
	for (int i = 0; i < lesserSize; i++)
	{
		int aInt = a[i] - '0';
		int bInt = b[i] - '0';

		int sum = aInt + bInt;

		if (isOver == true)
		{
			sum++;
		}

		// 10이 넘을 경우
		int sub = 0;
		if (sum >= 10)
		{
			sub = sum - 10;
			isOver = true;

			output += to_string(sub);
		}
		else
		{
			isOver = false;

			output += to_string(sum);
		}
	}

	for (int i = 0; i < biggerSize - lesserSize; i++)
	{
		int sum = biggerNumberStr[lesserSize + i] - '0';

		if (isOver == true)
		{
			sum++;
		}

		// 10이 넘을 경우
		int sub = 0;
		if (sum >= 10)
		{
			sub = sum - 10;
			isOver = true;

			output += to_string(sub);
		}
		else
		{
			isOver = false;

			output += to_string(sum);
		}
	}

	// 둘 째자리에 10이 넘으면 첫 째자리에 1 추가
	if (isOver == true)
	{
		output += "1";
	}

	output = Switching(output, output.size());

	cout << output;

	return 0;
}

string Switching(string s, int size)
{
	string c = "";
	for (int i = 0; i < size; i++)
	{
		c += s[size - 1 - i];
	}

	return c;
}
