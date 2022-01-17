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

		// �� ���� �ܾ��� �����ŭ ��
		if (size < 0)
			size = a.second;
		else
			size = b.second;
		
		for (int i = 0; i < size; i++)
		{
			// �ٸ� ������ �ѱ�
			if (a.first[i] == b.first[i])
				continue;

			// �ٸ��ٸ� ���� �������
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

	std::map<std::string, int> wordMap;					// �ߺ� üũ��
	std::vector<std::pair<std::string, int>> wordVec;	// ���Ŀ�

	for (int i = 0; i < n; i++)
	{
		std::string word;
		std::cin >> word;
		
		// �̹� �ִ� �ܾ��� �н�
		if (wordMap.count(word) > 0)
			continue;

		// ���� �Է� �޾Ҵ� �ܾ����� �ƴ��� üũ
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