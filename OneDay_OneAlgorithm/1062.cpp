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

	// anta, tica�� a,n,t,i,c�� �ʼ��� ������ϴ� ����
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

	// ���ĺ� ASCII, �������� üũ
	std::map<int, bool> checkMap;

	int countMax = k - 5;		// ��� �� �ִ� ���� ��
	int resultCountMax = 0;		// �ִ� ���� �� �ִ� �ܾ� ��

	// ��� ��츦 üũ
	do 
	{
		int count = 0;
		int resultCount = 0;		// max�� �񱳿� ī��Ʈ

		Init(checkMap);

		for (int i = 0; i < n; i++)
		{
			std::string input = inputStrVec[i];

			// ��� ���ڸ� ���� �ȴ�. anta, tica �̹� 5���� �Һ�
			std::string check = input.substr(4, input.size() - 8);

			bool isRead = true;
			for (int j = 0; j < check.size(); j++)
			{
				// ��� �� �ִ� ���� ���� �������� ��
				if (count <= countMax)
				{
					// üũ �ȵǾ��ִٸ�
					if (checkMap.count(check[j] - 'a') <= 0)
					{
						checkMap[check[j] - 'a'] = true;
						count++;
					}
				}

				// ���� ���ڰ� ���� �𸣴� ������ ���, �� �ܾ�� ���� �� ����
				if (checkMap.count(check[j] - 'a') <= 0)
				{
					isRead = false;
					break;
				}
			}

			// ���� �� �ִ°�?
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