#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
	if (a.second == b.second)
	{
		int size = a.second - b.second;

		// 더 작은 단어의 사이즈만큼 비교
		if (size < 0)
			size = a.second;
		else
			size = b.second;
		
		for (int i = 0; i < size; i++)
		{
			// 다를 때까지 넘김
			if (a.first[i] == b.first[i])
				continue;

			// 다르다면 사전 순서대로
			return a.first[i] < b.first[i];
		}
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	std::map<std::string, int> wordMap;					// 중복 체크용
	std::vector<std::pair<std::string, int>> wordVec;	// 정렬용

	for (int i = 0; i < n; i++)
	{
		std::string word;
		std::cin >> word;
		
		// 이미 있는 단어라면 패스
		if (wordMap.count(word) > 0)
			continue;

		// 전에 입력 받았던 단어인지 아닌지 체크
		wordMap[word] = 0;
		wordVec.emplace_back(std::pair<std::string, int>(word, word.size()));
	}

	sort(wordVec.begin(), wordVec.end(), compare);

	for (const auto& it : wordVec)
	{
		std::cout << it.first << "\n";
	}

	return 0;
}