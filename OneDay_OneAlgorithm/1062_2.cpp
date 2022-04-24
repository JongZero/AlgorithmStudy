#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n = 0;
int k = 0;
int readCountMax = 0;
vector<bool> alphaVec(26);	// 알파벳은 26개
vector<string> inputStrVec;

void Func(int index, int count)
{
	if (count == k)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			bool isRead = true;
			for (int j = 0; j < inputStrVec[i].size(); j++)
			{
				if (alphaVec[inputStrVec[i][j] - 'a'] == false)
				{
					isRead = false;
					break;
				}
			}

			if (isRead)
			{
				count++;
			}
		}

		if (readCountMax < count)
		{
			readCountMax = count;
		}

		return;
	}
	else
	{
		for (int i = index; i < 26; i++)
		{
			if (alphaVec[i] == true)
				continue;

			alphaVec[i] = true;
			Func(i, count + 1);
			alphaVec[i] = false;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> k;

	// a,n,t,i,c 는 필수로 배워야 하는 글자 (5개)
	// 따라서, 5개 이하의 단어만 가르치면 단어를 읽을 수 없음
	if (k < 5)
	{
		std::cout << 0;
		return 0;
	}

	// 5개는 빼고 생각해야함
	k -= 5;
	alphaVec['a' - 'a'] = true;
	alphaVec['n' - 'a'] = true;
	alphaVec['t' - 'a'] = true;
	alphaVec['i' - 'a'] = true;
	alphaVec['c' - 'a'] = true;

	inputStrVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputStrVec[i];

		// anta, tica는 빼고 생각
		inputStrVec[i] = inputStrVec[i].substr(4, inputStrVec[i].size() - 8);
	}

	Func(0, 0);

	std::cout << readCountMax;

	return 0;
}

