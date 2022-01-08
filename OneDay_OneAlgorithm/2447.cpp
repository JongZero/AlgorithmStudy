#include <iostream>
using namespace std;

void star(int n1, int n2, int inputN)
{
	if (0 == n1 && 0 == n2)
	{
		return;
	}
	else if (2 == n1 && 2 == n2)
	{
		cout << " ";
	}
	else
	{
		cout << "*";
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
				cout << "\n";
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

// 무조건 가운데를 지운다.
void star3(int k, int n2, int inputN, bool** numArray)
{
	// k는 횟수
	// n 3의 몇 제곱번 반복하는지 (2씩 증가)
	// count는 
	if (k == 0)
	{
		return;
	}

	

	if (n2 >= 0)
	{
		n2--;

		if (n2 == 0)
		{
			k--;

			if (k > 0)
			{
				n2 = inputN;
			}
		}
	}

	star3(k, n2, inputN, numArray);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	//star(n, n, n);
	bool** numArray = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		numArray[i] = new bool[n];
		memset(numArray[i], 1, sizeof(bool) * n);		// true로 초기화
	}

	int k = n / 3;
	star3(k, 0, n, numArray);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (numArray[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}