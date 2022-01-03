#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> kgVec(n);
	vector<int> cmVec(n);

	for (int i = 0; i < n; i++)
	{
		int kg, cm;
		cin >> kg >> cm;

		kgVec[i] = kg;
		cmVec[i] = cm;
	}

	// �ڽź��� ��ġ�� �� ū ����� ��
	vector<int> countVec(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			// Ű�� �� ũ�� kg�� �� ũ�ٸ�
			if (kgVec[i] < kgVec[j]
				&& cmVec[i] < cmVec[j])
			{
				countVec[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << countVec[i] + 1 << " ";
	}

	return 0;
}