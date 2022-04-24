#include <iostream>
#include <vector>

int n = 0;
int s = 0;
std::vector<int> inputVec;
std::vector<int> checkVec;
int countMin = 100001;

/* ��� ��츦 Ž���ϸ�, �ð� �ʰ�
void Func(int count, int sum)
{
	if (sum >= s)
	{
		if (count < countMin)
		{
			countMin = count;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (checkVec[i] == 0)
				continue;

			sum += checkVec[i];
			checkVec[i] = 0;
			Func(count + 1, sum);
			checkVec[i] = inputVec[i];
			sum -= checkVec[i];
		}
	}
}
*/

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> s;

	inputVec.resize(n);

	std::vector<int> resultVec;

	int start = 0;
	int end = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> inputVec[i];

		// �κ� �� ���ϱ�
		sum += inputVec[i];

		end++;

		// �κ� ���� s���� ũ�ٸ� �ּ����� üũ
		if (sum >= s)
		{
			// start�� �ϳ��� �ű�鼭, s �̻��̰�, �ּ����� üũ
			while (true)
			{
				int sub = end - start;

				if (sum < s)
				{
					break;
				}

				// �ּ����� üũ
				if (sub < countMin)
				{
					countMin = sub;
				}

				// �κ��տ��� ���� �κ��� sum���� ����
				sum -= inputVec[start];
				start++;
			}
		}
	}

	//checkVec = inputVec;
	//Func(0, 0);

	if (countMin == 100001)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << countMin;
	}

	return 0;
}
