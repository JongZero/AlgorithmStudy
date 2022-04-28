#include <iostream>
#include <vector>
#include <string>

int n = 0;
int k = 0;
std::vector<std::string> inputVec;
std::vector<bool> isAlphabetUsed(26);		// ���ĺ��� 26����

int resultMax = 0;

void Func(int count, int startIndex)
{
	if (count == k)
	{
		int tempResult = 0;

		// �˻�
		for (int i = 0; i < n; i++)
		{
			bool isRead = true;
			for (int j = 0; j < inputVec[i].size(); j++)
			{
				int index = inputVec[i][j] - 'a';

				if (isAlphabetUsed[index] == false)
				{
					// �𸣴� �ܾ ������ ������
					isRead = false;
					break;
				}
			}

			if (isRead)
			{
				tempResult++;
			}
		}

		if (tempResult > resultMax)
			resultMax = tempResult;
	}
	else
	{
		// ���ĺ��� ��ȸ�ϸ�, ��� �� �ִ� �� ���
		for (int i = startIndex; i < 26; i++)
		{
			if (isAlphabetUsed[i] == true)
				continue;

			isAlphabetUsed[i] = true;
			Func(count + 1, i + 1);
			isAlphabetUsed[i] = false;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// a,n,t,i,c�� �ʼ��� �������
	std::cin >> n >> k;

	inputVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		inputVec[i] = input.substr(4, input.size() - 8);
	}

	// 5���� �۴ٸ� �ƹ� �ܾ ���� �� ����
	if (k < 5)
	{
		std::cout << 0;
		return 0;
	}

	isAlphabetUsed['a' - 'a'] = true;
	isAlphabetUsed['n' - 'a'] = true;
	isAlphabetUsed['t' - 'a'] = true;
	isAlphabetUsed['i' - 'a'] = true;
	isAlphabetUsed['c' - 'a'] = true;

	// 5���� �����
	k -= 5;

	Func(0, 0);

	std::cout << resultMax;

	return 0;
}
