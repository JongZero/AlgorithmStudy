#include <iostream>
#include <vector>

// ���μ��ΰ�?
bool isCoprime(int n1, int n2, int& divideNum)
{
	// �� ���� ���� ã�´�.
	int count = 0;
	if (n1 < n2)
	{
		count = n1;
	}
	else
	{
		count = n2;
	}

	// ������� ã�´�.
	for (int i = divideNum; i <= count; i++)
	{
		// i�� n1�� n2�� ������
		if (n1 % i == 0 && n2 % i == 0)
		{
			// 1�̿��� ������� �����Ƿ� ���μҰ� �ƴ�
			divideNum = i;
			return false;
		}
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n1(0), n2(0);
	std::cin >> n1 >> n2;

	// �ִ� ������� ���� ����
	std::vector<int> divideNumVec;

	// ���μҸ� üũ�ϸ鼭 ���� ���� ������� �����´�.
	int divideNum = 2;
	
	// n1, n2�� ���μ� �� ������ �ݺ�
	while (!isCoprime(n1, n2, divideNum))
	{
		// ���� ���� ������� ������.
		n1 /= divideNum;
		n2 /= divideNum;

		divideNumVec.push_back(divideNum);
	}
	
	// �� ���� ���ٸ� 1�� �ִ�����
	// �ּҰ������ �� ���� ���� ��
	if (divideNumVec.size() == 0)
	{
		std::cout << 1 << '\n';
		std::cout << n1 * n2;
	}
	else
	{
		// �ִ� ����� ���
		int max = 1;
		for (int i = 0; i < divideNumVec.size(); i++)
		{
			max *= divideNumVec[i];
		}
		std::cout << max << '\n';

		// �ּ� ����� ���
		std::cout << max * n1 * n2;
	}

	return 0;
}