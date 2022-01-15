#include <iostream>
#include <cmath>
#include <string.h>

void star(int n1, int n2, int inputN)
{
	if (0 == n1 && 0 == n2)
	{
		return;
	}
	else if (2 == n1 && 2 == n2)
	{
		std::cout << " ";
	}
	else
	{
		std::cout << "*";
	}

	if (n2 >= 0)
	{
		n2--;

		if (n2 == 0)
		{
			n1--;

			if (n1 > 0)
			{
				n2 = inputN;
				std::cout << "\n";
			}
		}
	}

	star(n1, n2, inputN);
}

void star2(int n1, int n2, int inputN, bool** numArray)
{
	if (n1 == 0 && n2 == 0)
	{
		return;
	}

	for (int i = (inputN - n1) * 3; i < (inputN - n1) * 3 + 3; i++)
	{
		for (int j = (inputN - n2) * 3; j < (inputN - n2) * 3 + 3; j++)
		{
			if (i == (inputN - n1) * 3 + 1 && j == (inputN - n2) * 3 + 1)
			{
				numArray[i][j] = false;
			}
			else
				numArray[i][j] = true;
		}
	}

	if (n2 >= 0)
	{
		n2--;

		if (n2 == 0)
		{
			n1--;

			if (n1 > 0)
			{
				n2 = inputN;
			}
		}
	}

	star2(n1, n2, inputN, numArray);
}

// ������ ����� �����.
void star3(int n, int root, int powNum, int inputN, bool** numArray)
{
	// �� �̻� ����� ������ ��
	if (n <= 1)
	{
		return;
	}

	n /= 3;
	// 27�� ��� 1 -> 9 -> 81 ������ Ƚ���� ������
	int count = pow(root, powNum);

	int startI = n;
	int startJ = n;
	for (int c = 0; c < count; c++)
	{
		for (int i = startI; i < startI + n; i++)
		{
			for (int j = startJ; j < startJ + n; j++)
			{
				numArray[i][j] = false;
			}
		}

// 		system("cls");
// 
//  		// ���
//  		for (int i = 0; i < root * 9; i++)
//  		{
//  			for (int j = 0; j < root * 9; j++)
//  			{
//  				if (numArray[i][j] == true)
//  					std::cout << "*";
//  				else
//  					std::cout << " ";
//  			}
//  			std::cout << "\n";
//  		}

		startI += n * 3;

		if (startI > inputN)
		{
			startI = n;
			startJ += n * 3;
		}
	}

	star3(n, root, powNum + 1, inputN, numArray);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	// �ϴ� n * n��ŭ ���� �� �׸��� ����� ����Լ��� ����� ���
	bool** numArray = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		numArray[i] = new bool[n];
		memset(numArray[i], true, sizeof(bool) * n);		// true�� �ʱ�ȭ
	}

	int count = n / 3;
	star3(n, 9, 0, n, numArray);

	// ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (numArray[i][j] == true)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		delete[] numArray[i];
	}
	delete[] numArray;

	return 0;
}