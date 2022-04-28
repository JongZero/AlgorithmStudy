#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long s = 0;
	std::cin >> s;

	long long sum = 0;
	long long count = 0;
	for (int i = 1; i <= s; i++)
	{
		sum += i;
		count++;

		// ���� s�� �Ѿ��ٸ�, ���±��� ���� ���߿� �ϳ��� ���� s�� ���� �� �ִ�.
		// ex) s = 5, 1+2+3 ���� ���� �� 6������, ���� ���� ���� �� �ϳ��� 1�� ���� 5�� ���� �� ����
		if (sum > s)
		{
			count--;
			break;
		}
		else if (sum == s)
		{
			break;
		}
	}

	std::cout << count;

	return 0;
}