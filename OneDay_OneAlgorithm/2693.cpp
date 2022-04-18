#include <iostream>

void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

// 삽입 정렬
void sort(int* arr, int n)
{
	// 배열의 크기가 1이라면 리턴
	if (n < 2)
		return;

	// 1번째 원소부터
	for (int i = 1; i < n; i++)
	{
		// i번째 원소의 왼쪽을 체크
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

		// 배열에 입력을 받는다.
		for (int j = 0; j < 10; j++)
		{
			std::cin >> arr[j];
		}

		// 정렬한다. (큰 값부터 내림차순)
		sort(arr, 10);

		// 3번째 큰 값 (인덱스 2)를 출력
		std::cout << arr[2] << '\n';
	}

	return 0;
}