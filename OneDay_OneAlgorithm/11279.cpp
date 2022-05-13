#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int Max = 100000;
int heapData[Max + 2] = { 0, };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<int> resultVec;

	int n = 0;
	cin >> n;

	int size = 0;

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> input;

		// 최대값 출력 후 배열에서 제거
		if (input == 0)
		{
			// 배열이 비어있는 경우는 0 출력
			if (size == 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// 최대 값 출력 후
				resultVec.emplace_back(heapData[1]);

				// 제거
				heapData[1] = heapData[size];
				heapData[size] = 0;
				size--;

				// 자식 노드와 비교, 자식 노드 중 더 큰 값과 교환
				// 더 큰 값이 없으면 스탑
				int tempIndex = 1;
				while (true)
				{
					// 자식 노드가 우선 있는지 검사
					// 왼쪽
					int leftChild = 0;
					if (tempIndex * 2 <= size)
						leftChild = heapData[tempIndex * 2];

					// 오른쪽
					int rightChild = 0;
					if (tempIndex * 2 + 1 <= size)
						rightChild = heapData[tempIndex * 2 + 1];

					if (leftChild == 0 && rightChild == 0)
						break;

					// 자식 노드와 바꿀 필요가 있는지
					if (heapData[tempIndex] >= heapData[tempIndex * 2]
						&& heapData[tempIndex] >= heapData[tempIndex * 2 + 1])
						break;

					int temp = 0;
					// 왼쪽 자식이 더 클 경우
					if (leftChild > rightChild)
					{
						// 부모의 값과 자식의 값 교환
						temp = heapData[tempIndex];
						heapData[tempIndex] = heapData[tempIndex * 2];
						tempIndex = tempIndex * 2;
						heapData[tempIndex] = temp;
					}
					else
					{
						// 부모의 값과 자식의 값 교환
						temp = heapData[tempIndex];
						heapData[tempIndex] = heapData[tempIndex * 2 + 1];
						tempIndex = tempIndex * 2 + 1;
						heapData[tempIndex] = temp;
					}
				}
			}
		}
		// 배열에 x값 넣기
		else
		{
			size++;
			int tempInputIndex = size;

			// 인덱스 가장 마지막에 삽입
			heapData[tempInputIndex] = input;

			// 부모 노드와 비교해서, 교환해야하면 교환
			int parentIndex = tempInputIndex / 2;
			while (tempInputIndex > 1)
			{
				// 교환
				if (input > heapData[parentIndex])
				{
					heapData[tempInputIndex] = heapData[parentIndex];
					heapData[parentIndex] = input;
					tempInputIndex = parentIndex;
				}
				else
					break;

				parentIndex = tempInputIndex / 2;
			}
		}
	}

	for (int i = 0; i < resultVec.size(); i++)
	{
		cout << resultVec[i] << '\n';
	}

	return 0;
}