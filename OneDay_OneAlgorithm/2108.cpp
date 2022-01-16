#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int Max = 8001;

	int countArray[Max] = { 0, };

	int n = 0;
	std::cin >> n;
	int* numsArray = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> numsArray[i];
		numsArray[i] += 4000;

		countArray[numsArray[i]]++;
	}

	// �ϴ� ī���� ���� + �ִ� ī��Ʈ(�ֺ�) ã��
	int maxCount = 0;
	std::vector<int> maxCountIndexSameVec;
	for (int i = 0; i < Max; i++)
	{
		if (maxCount < countArray[i])
		{
			maxCount = countArray[i];
			maxCountIndexSameVec.clear();
			maxCountIndexSameVec.push_back(i);
		}
		// ���� �� ���� ���
		else if (maxCount == countArray[i])
		{
			maxCountIndexSameVec.push_back(i);
		}

		if (i != 0)
			countArray[i] = countArray[i - 1] + countArray[i];
	}
	
	// ī���� ���� + �� ���ϱ� + �ִ�, �ּ� ���ϱ�
	int* sortArray = new int[n];
	
	double sum = 0;
	int minNum = 4000;
	int maxNum = -4000;
	for (int i = n - 1; i >= 0; i--)
	{
		int count = countArray[numsArray[i]];
		countArray[numsArray[i]]--;
		sortArray[count - 1] = numsArray[i];

		// �ε����� �ƴ� ��¥ ����
		int num = numsArray[i] - 4000;
		sum += num;

		if (num < minNum)
			minNum = num;

		if (num > maxNum)
			maxNum = num;
	}
	
	/// �ݿø��� ������
	sum /= (double)n;
	double average = round(sum);
	std::cout << average << "\n";
	
	/// �߾Ӱ�
	int centerIndex = n / 2;
	int center = sortArray[centerIndex] - 4000;
	std::cout << center << "\n";

	/// �ֺ�
	int maxCountNum = 0;
	// 2�� �̻��� ���
	if (maxCountIndexSameVec.size() > 1)
	{
		sort(maxCountIndexSameVec.begin(), maxCountIndexSameVec.end());

		maxCountNum = maxCountIndexSameVec[1] - 4000;
	}
	else
	{
		maxCountNum = maxCountIndexSameVec[0] - 4000;
	}
	std::cout << maxCountNum << "\n";

	/// ����
	std::cout << maxNum - minNum << "\n";

	return 0;
}