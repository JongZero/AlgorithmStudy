#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	char s[10];
	cin.getline(s, 10);

	// 첫 번째 숫자와 두 번째 숫자를 분리해 저장한다.
	string firstNum = "";
	string secondNum = "";
	bool isFirstEnd = false;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			isFirstEnd = true;
			continue;
		}

		if (!isFirstEnd)
		{
			firstNum += s[i];
		}
		else
		{
			secondNum += s[i];
		}
	}
	
	// 첫 번째와 세 번째 숫자 스왑
	char firstSwap = firstNum[2];
	char secondSwap = secondNum[2];

	firstNum[2] = firstNum[0];
	secondNum[2] = secondNum[0];

	firstNum[0] = firstSwap;
	secondNum[0] = secondSwap;

	int first = stoi(firstNum);
	int second = stoi(secondNum);

	if (first > second)
		cout << first;
	else
		cout << second;

	return 0;
}