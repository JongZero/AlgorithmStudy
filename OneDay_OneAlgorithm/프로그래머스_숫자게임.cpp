#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pa;
vector<pa> pVec;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int j = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int now = A[i];
		while (true)
		{
			if (now < B[j])
			{
				answer++;
				j++;
				break;
			}
			j++;
			if (j >= B.size()) break;
		}
		if (j >= B.size()) break;
	}

	return answer;
}