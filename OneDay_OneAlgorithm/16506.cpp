#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;

string DecimalToBinary(int d, int size)
{
	string result;
	stack<string> resultStack;

	while (d > 1)
	{
		int temp = d % 2;
		if (temp == 0)
			resultStack.push("0");
		else
			resultStack.push("1");

		d /= 2;
	}

	resultStack.push(to_string(d));

	// size 보다 작은 경우 0을 추가적으로 붙여줌
	while (resultStack.size() < size)
	{
		resultStack.push("0");
	}

	while (!resultStack.empty())
	{
		result += resultStack.top();
		resultStack.pop();
	}

	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;
	cin.ignore();

	map<string, string> opcodeMap;
	opcodeMap["ADD"] = "0000";
	opcodeMap["SUB"] = "0001";
	opcodeMap["MOV"] = "0010";
	opcodeMap["AND"] = "0011";
	opcodeMap["OR"] = "0100";
	opcodeMap["NOT"] = "0101";
	opcodeMap["MULT"] = "0110";
	opcodeMap["LSFTL"] = "0111";
	opcodeMap["LSFTR"] = "1000";
	opcodeMap["ASFTR"] = "1001";
	opcodeMap["RL"] = "1010";
	opcodeMap["RR"] = "1011";

	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		string output;

		// opcode
		int offset = input.find(' ');
		string opcode = input.substr(0, offset);

		// #C 상수 사용여부
		bool isC = false;
		if (opcode[opcode.size() - 1] == 'C')
		{
			isC = true;
			opcode = opcode.substr(0, opcode.size() - 1);
		}

		// 0 ~ 3 bit, opcode
		output += opcodeMap[opcode];

		// 4 bit, 상수 여부
		if (isC)
			output += '1';
		else
			output += '0';

		// 5 bit
		output += '0';

		// 6 ~ 8 bit, rD
		offset++;
		int rDoffset = input.find(' ', offset);
		string rD = input.substr(offset, rDoffset - offset);
		rD = DecimalToBinary(stoi(rD), 3);

		output += rD;

		// 9 ~ 11, rA
		rDoffset++;
		int rAoffset = input.find(' ', rDoffset);
		if (opcode == "MOV" || opcode == "NOT")
		{
			output += "000";
		}
		else
		{
			string rA = input.substr(rDoffset, rAoffset - rDoffset);
			rA = DecimalToBinary(stoi(rA), 3);

			output += rA;
		}

		// 12 ~ 15
		rAoffset++;
		int cOffset = rAoffset;
		string c = input.substr(cOffset, input.size() - cOffset);

		if (isC)
		{
			c = DecimalToBinary(stoi(c), 4);
			output += c;
		}
		else
		{
			c = DecimalToBinary(stoi(c), 3);
			output += c;
			output += '0';
		}

		cout << output << '\n';
	}

	return 0;
}