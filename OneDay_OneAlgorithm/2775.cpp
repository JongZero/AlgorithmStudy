#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		// k층, n호
		int k, n;
		cin >> k >> n;

		if (k > 0)
		{
			// k * n 2차원 배열
			int** kn = new int* [k];
			for (int u = 0; u < k; u++)
			{
				kn[u] = new int[n];
			}

			// 0층에는 1,2,3,4,5... 명이 들어간다.
			for (int p = 0; p < n; p++)
			{
				kn[0][p] = p + 1;
			}

			if (k > 1)
			{
				// k - 1층의 n까지 구한다.
				for (int j = 1; j < k; j++)
				{
					for (int l = 0; l < n; l++)
					{
						// 현재 층의 n까지의 합
						int sum = 0;

						for (int b = 0; b <= l; b++)
						{
							sum += kn[j - 1][b];
							kn[j][l] = sum;
						}
					}
				}
			}

			// k - 1층의 n까지의 합
			int mySum = 0;
			for (int i = 0; i < n; i++)
			{
				mySum += kn[k - 1][i];
			}

			cout << mySum << "\n";

			// 2차원 배열 동적할당 해제
			for (int i = 0; i < k; i++)
			{
				delete[] kn[i];
			}

			delete[] kn;
		}
		// 0층일 경우
		else
		{
			cout << n << "\n";
		}
	}


	

	return 0;
}