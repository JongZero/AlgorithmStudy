#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int Max = 100000;
int heapData[Max + 2] = { 0, };
int heapSize = 0;

int absolute(int num)
{
	if (num < 0)
		return num * -1;
	else
		return num;
}

void push(int input)
{
	heapSize++;
	int tempInputIndex = heapSize;

	// 인덱스 가장 마지막에 삽입
	heapData[tempInputIndex] = input;

	// 부모 노드와 비교해서, 교환해야하면 교환
	int parentIndex = tempInputIndex / 2;
	while (tempInputIndex > 1)
	{
		int inputAbs = absolute(input);
		int parentAbs = absolute(heapData[parentIndex]);

		// 인풋 절댓값이 더 작다면, 부모로 올림
		if (inputAbs < parentAbs)
		{
			heapData[tempInputIndex] = heapData[parentIndex];
			heapData[parentIndex] = input;
			tempInputIndex = parentIndex;
		}
		// 절댓값이 같은 경우, 더 작은 수(음수)를 부모로 올림
		else if (inputAbs == parentAbs)
		{
			if (input < heapData[parentIndex])
			{
				heapData[tempInputIndex] = heapData[parentIndex];
				heapData[parentIndex] = input;
				tempInputIndex = parentIndex;
			}
			else
				break;
		}
		else
			break;

		parentIndex = tempInputIndex / 2;
	}
}

void pop()
{
	heapData[1] = heapData[heapSize];
	heapData[heapSize] = 0;
	heapSize--;

	// 자식 노드와 비교, 자식 노드 중 더 작은 값과 교환
	// 더 작은 값이 없으면 스탑
	int tempIndex = 1;
	while (true)
	{
		// 자식 노드가 우선 있는지 검사
		// 왼쪽
		int leftChild = 0;
		if (tempIndex * 2 <= heapSize)
			leftChild = heapData[tempIndex * 2];

		// 오른쪽
		int rightChild = 0;
		if (tempIndex * 2 + 1 <= heapSize)
			rightChild = heapData[tempIndex * 2 + 1];

		int swapIndex = 0;
		if (leftChild == 0 && rightChild == 0)
			break;

		if (leftChild == 0 || rightChild == 0)
		{
			if (leftChild == 0 
				&& absolute(heapData[tempIndex]) >= absolute(heapData[tempIndex * 2 + 1])
				&& heapData[tempIndex] > heapData[tempIndex * 2 + 1])
				swapIndex = tempIndex * 2 + 1;
			else if (rightChild == 0 
				&& absolute(heapData[tempIndex]) >= absolute(heapData[tempIndex * 2])
				&& heapData[tempIndex] > heapData[tempIndex * 2])
				swapIndex = tempIndex * 2;
		}

		// 자식 노드와 바꿀 필요가 있는지, 절댓값으로 비교
		if ((absolute(heapData[tempIndex]) <= absolute(heapData[tempIndex * 2]) 
			&& heapData[tempIndex] <= heapData[tempIndex * 2])
			&& (absolute(heapData[tempIndex]) <= absolute(heapData[tempIndex * 2 + 1])
			&& heapData[tempIndex] <= heapData[tempIndex * 2 + 1]))
			break;

		if (swapIndex == 0)
		{
			// 오른쪽 자식이 더 클 경우, 절댓 값이 더 작은 값인 왼쪽과 교환
			if (absolute(leftChild) < absolute(rightChild))
			{
				swapIndex = tempIndex * 2;
			}
			// 절댓값이 같다면, 더 작은 값과 교환
			else if (absolute(leftChild) == absolute(rightChild))
			{
				if (leftChild < rightChild)
				{
					swapIndex = tempIndex * 2;
				}
				else
				{
					swapIndex = tempIndex * 2 + 1;
				}
			}
			else
			{
				swapIndex = tempIndex * 2 + 1;
			}
		}

		// 부모의 값과 자식의 값 교환
		int temp = 0;
		temp = heapData[tempIndex];
		heapData[tempIndex] = heapData[swapIndex];
		tempIndex = swapIndex;
		heapData[tempIndex] = temp;
	}
}

int front()
{
	if (heapSize > 0)
		return heapData[1];
	else
		return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<int> resultVec;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> input;

		// 최대값 출력 후 배열에서 제거
		if (input == 0)
		{
			// 배열이 비어있는 경우는 0 출력
			if (heapSize == 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// 최대 값 출력 후
				//cout << "out : " << front() << '\n';
				resultVec.emplace_back(front());

				// 제거
				pop();
			}
		}
		// 배열에 x값 넣기
		else
		{
			push(input);
		}

		//cout << "now heap : ";
		//for (int j = 1; j <= heapSize; j++)
		//{
		//	cout << heapData[j] << ' ';
		//}
		//cout << '\n';
	}

	for (int i = 0; i < resultVec.size(); i++)
	{
		cout << resultVec[i] << '\n';
	}

	return 0;
}