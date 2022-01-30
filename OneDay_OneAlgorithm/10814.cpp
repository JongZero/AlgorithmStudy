#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(std::pair<int, std::pair<int, std::string>> h1, std::pair<int, std::pair<int, std::string>> h2)
{
	// 나이가 같다면
	if (h1.second.first == h2.second.first)
	{
		return h1.first < h2.first;
	}

	return h1.second.first < h2.second.first;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;
	std::vector<std::pair<int, std::pair<int, std::string>>> vec(n);

	for (int i = 0; i < n; i++)
	{
		int age = 0;
		std::string name;

		std::cin >> age >> name;
		std::pair<int, std::pair<int, std::string>> ageName(i, std::pair<int, std::string>(age, name));

		vec[i] = ageName;
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++)
	{
		std::cout << vec[i].second.first << " " << vec[i].second.second << "\n";
	}

	return 0;
}