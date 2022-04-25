#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int k = 0;
int resultCount = 0;
int n = 0;
std::vector<int> inputVec;
std::vector<int> countVec;
std::vector<int> originalCountVec;
std::unordered_map<std::string, bool> checkMap;

void Func(int sum)
{
	if (sum > k)
	{
		return;
	}
	else if (sum == k)
	{
		// 동전의 구성이 같은데, 순서만 다른 것인지 조사한다.
		std::string str;
		for (int i = 0; i < n; i++)
		{
			str += (originalCountVec[i] - countVec[i]) % 10;
		}

		// 이미 있다면 중복이다.
		// 없을 경우에만
		if (checkMap.count(str) <= 0)
		{
			checkMap[str] = true;
			resultCount++;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			// 사용 횟수가 없으면 넘김
			if (countVec[i] <= 0)
			{
				continue;
			}

			// 사용
			countVec[i]--;

			Func(sum + inputVec[i]);

			// 리셋
			countVec[i]++;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;
	std::cin >> k;

	inputVec.resize(n);
	countVec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		countVec[i] = k / inputVec[i];	// 10번 사용 가능
	}

	originalCountVec = countVec;

	for (int i = 0; i < n; i++)
	{
		// 나누어 떨어진다면, 그 동전만으로 k원 가치 도달 가능
		if (k % inputVec[i] == 0)
		{
			resultCount++;

			int temp = countVec[i];
			countVec[i] = 0;

			// 해쉬 맵에 이미 검사했다고 등록
			std::string str;
			for (int i = 0; i < n; i++)
			{
				str += (originalCountVec[i] - countVec[i]) % 10;
			}

			checkMap[str] = true;
			countVec[i] = temp;
		}
	}

	Func(0);

	std::cout << resultCount;
	return 0;
}
