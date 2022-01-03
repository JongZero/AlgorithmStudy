#include <iostream>
using namespace std;

int main()
{
	int c = 0;

	cin >> c;

	// ���̽� c ���� ��ŭ �迭 ����
	float* averageArray = new float[c];

	for (int i = 0; i < c; i++)
	{
		// �л��� ��
		int n = 0;

		cin >> n;

		// �л� n���� ����ŭ �迭 ����
		int* scoreArray = new int[n];

		// n���� ����
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int score = 0;

			cin >> score;

			scoreArray[j] = score;

			sum += scoreArray[j];
		}

		// ������ ��� ����.
		float average = (float)sum / (float)n;

		// ��� ������ �Ѵ� �л����� ��
		int checkCount = 0;
		for (int k = 0; k < n; k++)
		{
			if (scoreArray[k] > average)
				checkCount++;
		}

		averageArray[i] = (float)checkCount / (float)n * 100.0f;

		delete[] scoreArray;
		scoreArray = nullptr;
	}

	for (int i = 0; i < c; i++)
	{
		printf("%.3f", averageArray[i]);
		cout << "%" << '\n';
	}

	delete[] averageArray;
	averageArray = nullptr;

	return 0;
}