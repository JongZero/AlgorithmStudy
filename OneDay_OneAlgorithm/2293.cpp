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
		// ������ ������ ������, ������ �ٸ� ������ �����Ѵ�.
		std::string str;
		for (int i = 0; i < n; i++)
		{
			str += (originalCountVec[i] - countVec[i]) % 10;
		}

		// �̹� �ִٸ� �ߺ��̴�.
		// ���� ��쿡��
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
			// ��� Ƚ���� ������ �ѱ�
			if (countVec[i] <= 0)
			{
				continue;
			}

			// ���
			countVec[i]--;

			Func(sum + inputVec[i]);

			// ����
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

		countVec[i] = k / inputVec[i];	// 10�� ��� ����
	}

	originalCountVec = countVec;

	for (int i = 0; i < n; i++)
	{
		// ������ �������ٸ�, �� ���������� k�� ��ġ ���� ����
		if (k % inputVec[i] == 0)
		{
			resultCount++;

			int temp = countVec[i];
			countVec[i] = 0;

			// �ؽ� �ʿ� �̹� �˻��ߴٰ� ���
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
