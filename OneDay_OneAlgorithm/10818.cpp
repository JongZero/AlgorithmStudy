#include <iostream>
using namespace std;

/// 10818
// 문제
// N개의 정수가 주어진다.이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 정수의 개수 N(1 ≤ N ≤ 1, 000, 000)이 주어진다.둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
// 모든 정수는 - 1, 000, 000보다 크거나 같고, 1, 000, 000보다 작거나 같은 정수이다.
// 
// 출력
// 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

/// 문제의 입력 조건 (음수가 입력될 수 있다는)을 제대로 읽지 않아서
/// 여러 번 틀렸다. (5번?) 
/// 문제를 꼼꼼히 읽자

int main()
{
	int n = 0;

	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	int* numbers = new int[n];

	int min = 1000000;
	int max = -1000000;

	for (int i = 0; i < n; i++)
	{
		int inputNum = 0;

		cin >> inputNum;

		numbers[i] = inputNum;

		if (numbers[i] < min)
		{
			min = numbers[i];
		}

		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	cout << min << " " << max;

	return 0;
}