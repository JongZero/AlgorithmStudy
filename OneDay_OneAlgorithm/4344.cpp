#include <iostream>
using namespace std;

int main()
{
	int c = 0;

	cin >> c;

	// 케이스 c 개수 만큼 배열 생성
	float* averageArray = new float[c];

	for (int i = 0; i < c; i++)
	{
		// 학생의 수
		int n = 0;

		cin >> n;

		// 학생 n명의 수만큼 배열 생성
		int* scoreArray = new int[n];

		// n명의 점수
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int score = 0;

			cin >> score;

			scoreArray[j] = score;

			sum += scoreArray[j];
		}

		// 점수를 평균 낸다.
		float average = (float)sum / (float)n;

		// 평균 점수를 넘는 학생들의 수
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