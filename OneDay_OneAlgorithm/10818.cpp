#include <iostream>
using namespace std;

/// 10818
// ����
// N���� ������ �־�����.�̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ������ ���� N(1 �� N �� 1, 000, 000)�� �־�����.��° �ٿ��� N���� ������ �������� �����ؼ� �־�����.
// ��� ������ - 1, 000, 000���� ũ�ų� ����, 1, 000, 000���� �۰ų� ���� �����̴�.
// 
// ���
// ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.

/// ������ �Է� ���� (������ �Էµ� �� �ִٴ�)�� ����� ���� �ʾƼ�
/// ���� �� Ʋ�ȴ�. (5��?) 
/// ������ �Ĳ��� ����

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