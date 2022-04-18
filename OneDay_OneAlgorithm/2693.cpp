#include <iostream>

void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

// ���� ����
void sort(int* arr, int n)
{
	// �迭�� ũ�Ⱑ 1�̶�� ����
	if (n < 2)
		return;

	// 1��° ���Һ���
	for (int i = 1; i < n; i++)
	{
		// i��° ������ ������ üũ
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int arr[10] = { 0, };

		// �迭�� �Է��� �޴´�.
		for (int j = 0; j < 10; j++)
		{
			std::cin >> arr[j];
		}

		// �����Ѵ�. (ū ������ ��������)
		sort(arr, 10);

		// 3��° ū �� (�ε��� 2)�� ���
		std::cout << arr[2] << '\n';
	}

	return 0;
}