#include <iostream>
#include <string>
using namespace std;

string Switching(string s, int size);

int main()
{
	string a, b, output;
	cin >> a >> b;

	// ������ ��
	int sizeA = a.size();
	int sizeB = b.size();

	string biggerNumberStr;		// �� ū ���� ��Ʈ��

	int lesserSize = 0;			// �� ū ������
	int biggerSize = 0;			// �� ���� ������
	if (sizeA > sizeB)
	{
		lesserSize = sizeB;
		biggerSize = sizeA;

		biggerNumberStr = a;
	}
	else
	{
		lesserSize = sizeA;
		biggerSize = sizeB;

		biggerNumberStr = b;
	}

	// ����Ī �Ѵ�. �� �ڸ� �ٲ۴�.
	a = Switching(a, sizeA);
	b = Switching(b, sizeB);
	biggerNumberStr = Switching(biggerNumberStr, biggerNumberStr.size());

	// 10�� �Ѿ����� (�Ѿ��ٸ� ���� �ڸ��� +1 �������)
	bool isOver = false;

	// a, b �߿� ���� �ڸ����� ������ ��� �����ش�.
	for (int i = 0; i < lesserSize; i++)
	{
		int aInt = a[i] - '0';
		int bInt = b[i] - '0';

		int sum = aInt + bInt;

		if (isOver == true)
		{
			sum++;
		}

		// 10�� ���� ���
		int sub = 0;
		if (sum >= 10)
		{
			sub = sum - 10;
			isOver = true;

			output += to_string(sub);
		}
		else
		{
			isOver = false;

			output += to_string(sum);
		}
	}

	for (int i = 0; i < biggerSize - lesserSize; i++)
	{
		int sum = biggerNumberStr[lesserSize + i] - '0';

		if (isOver == true)
		{
			sum++;
		}

		// 10�� ���� ���
		int sub = 0;
		if (sum >= 10)
		{
			sub = sum - 10;
			isOver = true;

			output += to_string(sub);
		}
		else
		{
			isOver = false;

			output += to_string(sum);
		}
	}

	// �� °�ڸ��� 10�� ������ ù °�ڸ��� 1 �߰�
	if (isOver == true)
	{
		output += "1";
	}

	output = Switching(output, output.size());

	cout << output;

	return 0;
}

string Switching(string s, int size)
{
	string c = "";
	for (int i = 0; i < size; i++)
	{
		c += s[size - 1 - i];
	}

	return c;
}
