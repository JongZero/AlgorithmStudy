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

	// �ε��� ���� �������� ����
	heapData[tempInputIndex] = input;

	// �θ� ���� ���ؼ�, ��ȯ�ؾ��ϸ� ��ȯ
	int parentIndex = tempInputIndex / 2;
	while (tempInputIndex > 1)
	{
		int inputAbs = absolute(input);
		int parentAbs = absolute(heapData[parentIndex]);

		// ��ǲ ������ �� �۴ٸ�, �θ�� �ø�
		if (inputAbs < parentAbs)
		{
			heapData[tempInputIndex] = heapData[parentIndex];
			heapData[parentIndex] = input;
			tempInputIndex = parentIndex;
		}
		// ������ ���� ���, �� ���� ��(����)�� �θ�� �ø�
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

	// �ڽ� ���� ��, �ڽ� ��� �� �� ���� ���� ��ȯ
	// �� ���� ���� ������ ��ž
	int tempIndex = 1;
	while (true)
	{
		// �ڽ� ��尡 �켱 �ִ��� �˻�
		// ����
		int leftChild = 0;
		if (tempIndex * 2 <= heapSize)
			leftChild = heapData[tempIndex * 2];

		// ������
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

		// �ڽ� ���� �ٲ� �ʿ䰡 �ִ���, �������� ��
		if ((absolute(heapData[tempIndex]) <= absolute(heapData[tempIndex * 2]) 
			&& heapData[tempIndex] <= heapData[tempIndex * 2])
			&& (absolute(heapData[tempIndex]) <= absolute(heapData[tempIndex * 2 + 1])
			&& heapData[tempIndex] <= heapData[tempIndex * 2 + 1]))
			break;

		if (swapIndex == 0)
		{
			// ������ �ڽ��� �� Ŭ ���, ���� ���� �� ���� ���� ���ʰ� ��ȯ
			if (absolute(leftChild) < absolute(rightChild))
			{
				swapIndex = tempIndex * 2;
			}
			// ������ ���ٸ�, �� ���� ���� ��ȯ
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

		// �θ��� ���� �ڽ��� �� ��ȯ
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

		// �ִ밪 ��� �� �迭���� ����
		if (input == 0)
		{
			// �迭�� ����ִ� ���� 0 ���
			if (heapSize == 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// �ִ� �� ��� ��
				//cout << "out : " << front() << '\n';
				resultVec.emplace_back(front());

				// ����
				pop();
			}
		}
		// �迭�� x�� �ֱ�
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