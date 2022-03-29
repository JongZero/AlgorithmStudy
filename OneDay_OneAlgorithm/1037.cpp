#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;
	std::vector<int> divisorVec(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> divisorVec[i];
	}

	// ������� ����
	sort(divisorVec.begin(), divisorVec.end());

	const int Max = 1000000;
	const int Min = 2;

	unsigned int result = 0;
	for (unsigned int i = Min; i <= Max; i++)
	{
		if (i == 2401)
		{
			int ee = 0;
		}

		// ������ ������������� �˻�
		bool check = true;
		for (int j = 0; j < n; j++)
		{
			// ����� ���ų�, ����������� �ʴ´ٸ�
			// �н�
			if (i == divisorVec[j]
				|| i % divisorVec[j] != 0)
			{
				check = false;
				break;
			}
		}

		// ��� ������ �������ٸ�
		if (check)
		{
			/// ��¥ ������� �����ؾ���
			// (����) �Է� : 3 / 7 49 343 
			// -> ���� : 2401
			// �� ���� ó�������� �� : 686
			// 686�� ��¥ ������� 2�� �ִ�. �׷��� �Է����� ���� 3���� ���� �߿� 2�� ����
			// �������� ��¥ ����� '���' �־����ٰ� �����Ƿ� Ʋ����.

			// 2���� ���鼭, �ϳ��� �Է����� ���� �� ������ �ƿ�
			bool isExist = false;
			for (int k = Min; k <= Max; k++)
			{
				// ������ �������� �� �߿�
				if (i % k == 0)
				{
					for (int o = 0; o < n; o++)
					{
						// �Է����� ���Դ°�?
						// �ȵ��Դٸ� ��!
						if (k == divisorVec[o])
						{
							isExist = true;
							break;
						}
					}

					// �Է����� ���°� ���ٸ� �� �˻��� �ʿ䵵 ����
					// Ʋ�� ���̴�. Ʋ�� ������ 54���ٺ���
					if (!isExist)
						break;
				}
			}

			// �Է����� ��� ���Դٸ� �´� ���
			if (isExist)
			{
				result = i;
				break;
			}
		}
	}

	std::cout << result;

	return 0;
}