#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string input;
	getline(cin, input);

	// 기본 변수형
	int basic = input.find(' ');
	string basicStr = input.substr(0, basic);

	// 변수명, 추가 변수형
	vector<string> output;
	int offset = 0;
	while (true)
	{
		offset = input.find(" ", offset + 1);

		if (offset == string::npos)
			break;

		int addStrEnd = input.find(",", offset + 1);

		// 맨 마지막 변수라면
		if (addStrEnd == string::npos)
		{
			addStrEnd = input.find(";", offset + 1);
		}

		// 변수명 찾기
		string addStr = input.substr(offset + 1, addStrEnd - (offset + 1));

		string name;
		for (int i = 0; i < addStr.size(); i++)
		{
			// 알파벳이라면 이름
			if (('a' <= addStr[i] && addStr[i] <= 'z') || ('A' <= addStr[i] && addStr[i] <= 'Z'))
				name += addStr[i];
			else
				break;
		}

		string resultStr = basicStr;
		// 추가 변수형을 순서를 뒤집어서 붙힘
		for (int i = addStr.size() - 1; i >= 0; i--)
		{
			if (('a' <= addStr[i] && addStr[i] <= 'z') || ('A' <= addStr[i] && addStr[i] <= 'Z'))
				break;

			char addChar = addStr[i];
			if (addStr[i] == '[')
				addChar = ']';
			else if (addStr[i] == ']')
				addChar = '[';

			resultStr += addChar;
		}

		// 변수명과 변수형 사이에 공백
		resultStr += ' ';
		// 변수명
		resultStr += name;
		// ;
		resultStr += ';';

		output.emplace_back(resultStr);
	}

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << '\n';
	}

	return 0;
}