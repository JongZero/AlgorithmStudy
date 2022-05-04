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

	// �⺻ ������
	int basic = input.find(' ');
	string basicStr = input.substr(0, basic);

	// ������, �߰� ������
	vector<string> output;
	int offset = 0;
	while (true)
	{
		offset = input.find(" ", offset + 1);

		if (offset == string::npos)
			break;

		int addStrEnd = input.find(",", offset + 1);

		// �� ������ �������
		if (addStrEnd == string::npos)
		{
			addStrEnd = input.find(";", offset + 1);
		}

		// ������ ã��
		string addStr = input.substr(offset + 1, addStrEnd - (offset + 1));

		string name;
		for (int i = 0; i < addStr.size(); i++)
		{
			// ���ĺ��̶�� �̸�
			if (('a' <= addStr[i] && addStr[i] <= 'z') || ('A' <= addStr[i] && addStr[i] <= 'Z'))
				name += addStr[i];
			else
				break;
		}

		string resultStr = basicStr;
		// �߰� �������� ������ ����� ����
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

		// ������� ������ ���̿� ����
		resultStr += ' ';
		// ������
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