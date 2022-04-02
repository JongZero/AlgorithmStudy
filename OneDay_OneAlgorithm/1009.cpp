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

	// ���� ����
	// ���̵�� : �ּ����� ��� Ƚ���� ���� ���ϰ�, ����Ѵ�. (������ĢȰ��)
	// ex) 2�� 100���� (��� Ƚ�� : 100��)
	// 2�� 100���� = 2�� ������ 50���� (51�� = ���� 1�� + 50���� 50��)
	// 2�� ������ 50���� = 2�� ������ ������ 25���� (27�� = ���� 2�� + 25���� 25��)
	// 2�� ������ ������ 25���� = 2�� ������ ������ ������ 12���� * 2�� 4���� (19�� = ���� 3�� + 12���� 12�� + ������ 4��)
	// �̷������� ��� Ƚ���� �ּҰ� �Ǵ� ���� ���ؼ� �׿� �´� ����� ���ش�.
	// ���� �����ϱⰡ ��ƴ�...
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;

		// �� �� ������ ������ ī��Ʈ
		int bCount = 0;

		// bCount��ŭ ������ �ϰ��� ���� ����,
		// a�� remainderCount������ ���� ���̴�.
		int remainder = 1;
		int remainderCount = 0;

		// ��� Ƚ��
		int prev = 1000000;
		int now = 0;

		while (true)
		{
			if (b < 2)
			{
				break;
			}

			// Ȧ����� �������� �����. (�������� 2�� ������ ���� Ƚ�� ����)
			if (b % 2 == 1)
			{
				remainderCount += remainder;
			}

			int prevB = b;
			b /= 2;
			bCount++;
			remainder = pow(2, bCount);

			now = bCount + b + remainderCount;

			// ���� Ƚ���� ������ Ƚ������ ���ٸ�
			// ������ Ƚ���� �ּ� Ƚ����
			if (now > prev)
			{
				b = prevB;
				bCount--;
				remainderCount -= pow(2, bCount);
				break;
			}

			prev = now;
		}

		/// �������� ���ش�.
		int mul = a;
		char mulChar = '1';
		std::string mulStr = "";
		for (int j = 0; j < bCount; j++)
		{
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			mul = mulChar - '0';
			mul *= mul;
		}

		/// b����ŭ mul�� ����
		// �� ������ �ڸ����� �ʿ�
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';
		int bResult = mul;
		for (int j = 0; j < b - 1; j++)
		{
			mulStr = std::to_string(mul);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			mul = mulChar - '0';
			mul *= bResult;
		}

		// �� ������ �ڸ����� �ʿ�
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';

		/// ������ ��� (a�� remainderCount ����)
		int remainderResult = 1;
		for (int j = 0; j < remainderCount; j++)
		{
			mulStr = std::to_string(remainderResult);
			mulChar = mulStr[mulStr.length() - 1];

			// char to int
			remainderResult = mulChar - '0';
			remainderResult *= a;
		}
		
		// ���� ��ģ��.
		mul *= remainderResult;

		// �� ������ �ڸ����� ���������� ���Ѵ�.
		mulStr = std::to_string(mul);
		mulChar = mulStr[mulStr.length() - 1];
		mul = mulChar - '0';

		// 0�̸� 10�� ��ǻ��
		if (mul == 0)
		{
			std::cout << 10 << '\n';
		}
		else
		{
			std::cout << mul << '\n';
		}
	}

	return 0;
}