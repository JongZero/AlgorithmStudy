#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	// 盖 菊 贸府
	int f = stations.front();
	int fResult = (f - 1 - w);
	if (fResult > 0)
	{
		fResult = fResult / (w + 1);
		if (fResult == 0) answer++;
		else answer += fResult;
	}
	//cout << "盖菊: " << answer << '\n';

	for (int i = 1; i < stations.size(); i++)
	{
		int temp = stations[i] - stations[i - 1] - 1;
		temp = temp - (w * 2);
		if (temp == 0) continue;
		temp = temp / (w + 1);
		if (temp == 0) answer++;
		else answer += temp;
		//cout << "i: " << i << " answer: " << answer << '\n';
	}

	// 盖 第 贸府
	int b = stations.back();
	//cout << "b: " << b << '\n';
	int bResult = (n - b - w);
	if (bResult > 0)
	{
		bResult = bResult / (w + 1);
		if (bResult == 0) answer++;
		else answer += bResult;
	}
	//cout << "bResult: " << bResult << '\n';
	//cout << "盖第: " << answer << '\n';

	return answer;
}