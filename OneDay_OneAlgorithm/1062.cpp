#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int n = 0;
int k = 0;

void Init(std::map<int, bool>& _map)
{
	_map.clear();

	// anta, tica의 a,n,t,i,c는 필수로 배워야하는 글자
	_map['a' - 'a'] = true;
	_map['n' - 'a'] = true;
	_map['t' - 'a'] = true;
	_map['i' - 'a'] = true;
	_map['c' - 'a'] = true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> k;

	std::vector<std::string> inputStrVec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputStrVec[i];
		std::string input = inputStrVec[i];
	}

	// 알파벳 ASCII, 쓰였는지 체크
	std::map<int, bool> checkMap;

	int countMax = k - 5;		// 배울 수 있는 글자 수
	int resultCountMax = 0;		// 최대 읽을 수 있는 단어 수

	// 모든 경우를 체크
	do 
	{
		int count = 0;
		int resultCount = 0;		// max와 비교용 카운트

		Init(checkMap);

		for (int i = 0; i < n; i++)
		{
			std::string input = inputStrVec[i];

			// 가운데 문자만 보면 된다. anta, tica 이미 5글자 소비
			std::string check = input.substr(4, input.size() - 8);

			bool isRead = true;
			for (int j = 0; j < check.size(); j++)
			{
				// 배울 수 있는 글자 수가 남아있을 때
				if (count <= countMax)
				{
					// 체크 안되어있다면
					if (checkMap.count(check[j] - 'a') <= 0)
					{
						checkMap[check[j] - 'a'] = true;
						count++;
					}
				}

				// 지금 글자가 내가 모르는 글자일 경우, 이 단어는 읽을 수 없음
				if (checkMap.count(check[j] - 'a') <= 0)
				{
					isRead = false;
					break;
				}
			}

			// 읽을 수 있는가?
			if (isRead)
			{
				resultCount++;
			}
		}

		if (resultCount > resultCountMax)
		{
			resultCountMax = resultCount;
		}

	} while (next_permutation(inputStrVec.begin(), inputStrVec.end()));

	std::cout << resultCountMax;

	return 0;
}