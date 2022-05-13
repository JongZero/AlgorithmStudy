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

		// �ִ밪 ��� �� �迭���� ����
		if (input == 0)
		{
			// �迭�� ����ִ� ���� 0 ���
			if (size == 0)
			{
				resultVec.emplace_back(0);
			}
			else
			{
				// �ִ� �� ��� ��
				resultVec.emplace_back(heapData[1]);

				// ����
				heapData[1] = heapData[size];
				heapData[size] = 0;
				size--;

				// �ڽ� ���� ��, �ڽ� ��� �� �� ū ���� ��ȯ
				// �� ū ���� ������ ��ž
				int tempIndex = 1;
				while (true)
				{
					// �ڽ� ��尡 �켱 �ִ��� �˻�
					// ����
					int leftChild = 0;
					if (tempIndex * 2 <= size)
						leftChild = heapData[tempIndex * 2];

					// ������
					int rightChild = 0;
					if (tempIndex * 2 + 1 <= size)
						rightChild = heapData[tempIndex * 2 + 1];

					if (leftChild == 0 && rightChild == 0)
						break;

					// �ڽ� ���� �ٲ� �ʿ䰡 �ִ���
					if (heapData[tempIndex] >= heapData[tempIndex * 2]
						&& heapData[tempIndex] >= heapData[tempIndex * 2 + 1])
						break;

					int temp = 0;
					// ���� �ڽ��� �� Ŭ ���
					if (leftChild > rightChild)
					{
						// �θ��� ���� �ڽ��� �� ��ȯ
						temp = heapData[tempIndex];
						heapData[tempIndex] = heapData[tempIndex * 2];
						tempIndex = tempIndex * 2;
						heapData[tempIndex] = temp;
					}
					else
					{
						// �θ��� ���� �ڽ��� �� ��ȯ
						temp = heapData[tempIndex];
						heapData[tempIndex] = heapData[tempIndex * 2 + 1];
						tempIndex = tempIndex * 2 + 1;
						heapData[tempIndex] = temp;
					}
				}
			}
		}
		// �迭�� x�� �ֱ�
		else
		{
			size++;
			int tempInputIndex = size;

			// �ε��� ���� �������� ����
			heapData[tempInputIndex] = input;

			// �θ� ���� ���ؼ�, ��ȯ�ؾ��ϸ� ��ȯ
			int parentIndex = tempInputIndex / 2;
			while (tempInputIndex > 1)
			{
				// ��ȯ
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