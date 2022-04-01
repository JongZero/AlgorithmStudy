#include <iostream>
#include <string>
#include <math.h>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// �ð� �ʰ� ����
	/*
	int t = 0;
	std::cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		int mul = 1;
		char mulChar = '1';
		std::string mulStr = "";

		// 1�� �ڸ��� ��� �˰��ְ�,
		// 1�� �ڸ��� b�� ��ŭ a�� �����ָ� �ȴ�.
		// ��Ʈ���� Ȱ���� 1�� �ڸ��� �����س��´�.
		for (int j = 0; j < b; j++)
		{
			// char to int
			mul = mulChar - '0';
			mul *= a;
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
		}

		// char to int
		int result = mulChar - '0';

		// ���
		std::cout << result << '\n';
	}
	*/

	// ���� ����
	// ���� Ȱ�� - �ð� �ʰ�
	/*
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		// b�� Ȧ���ΰ�?
		bool isOdd = false;
		if (b % 2 == 1)
			isOdd = true;

		b /= 2;		// ������ ���̱� ������ b�� 2�� �����ش�.

		int mul = 1;
		char mulChar = '1';
		std::string mulStr = "";

		// 1�� �ڸ��� ��� �˰��ְ�,
		// 1�� �ڸ��� b�� ��ŭ a�� �����ָ� �ȴ�.
		// ��Ʈ���� Ȱ���� 1�� �ڸ��� �����س��´�.
		for (int j = 0; j < b; j++)
		{
			// char to int
			mul = mulChar - '0';
			mul *= a;
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
		}

		// �� ������ �ڸ����� �ʿ�
		mul = mulChar - '0';

		mul *= mul;	// ����
		
		// Ȧ����� �ѹ� �� �����ش�.
		if (isOdd)
			mul *= a;

		// ���������� �� ������ �ڸ����� �ʿ�
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
			
		// char to int
		int result = mulChar - '0';

		if (result == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			// ���
			std::cout << result << '\n';
		}
		
	}
	*/

	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		int mul = a;
		char mulChar = '1';
		std::string mulStr = "";
		
		while (b >= 1)
		{	
			// ����
			// char to int
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];
			mul = mulChar - '0';
			mul *= mul;

			// ���������Ƿ� ������ ��� 2�� ������
			b /= 2;
		}

		// ������ �ڸ����� �����.
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		int result = mulChar - '0';

		if (result == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			// ���
			std::cout << result << '\n';
		}
	}

	return 0;
}