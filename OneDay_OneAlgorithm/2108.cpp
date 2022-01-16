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

	// 일단 카운팅 정렬 + 최다 카운트(최빈값) 찾기
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
		// 여러 개 있을 경우
		else if (maxCount == countArray[i])
		{
			maxCountIndexSameVec.push_back(i);
		}

		if (i != 0)
			countArray[i] = countArray[i - 1] + countArray[i];
	}
	
	// 카운팅 정렬 + 합 구하기 + 최대, 최소 구하기
	int* sortArray = new int[n];
	
	double sum = 0;
	int minNum = 4000;
	int maxNum = -4000;
	for (int i = n - 1; i >= 0; i--)
	{
		int count = countArray[numsArray[i]];
		countArray[numsArray[i]]--;
		sortArray[count - 1] = numsArray[i];

		// 인덱스가 아닌 진짜 숫자
		int num = numsArray[i] - 4000;
		sum += num;

		if (num < minNum)
			minNum = num;

		if (num > maxNum)
			maxNum = num;
	}
	
	/// 반올림한 산술평균
	sum /= (double)n;
	double average = round(sum);
	std::cout << average << "\n";
	
	/// 중앙값
	int centerIndex = n / 2;
	int center = sortArray[centerIndex] - 4000;
	std::cout << center << "\n";

	/// 최빈값
	int maxCountNum = 0;
	// 2개 이상일 경우
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

	/// 범위
	std::cout << maxNum - minNum << "\n";

	return 0;
}