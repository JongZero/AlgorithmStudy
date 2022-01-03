#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	vector<int> pointXVec;
	vector<int> pointYVec;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;

		pointXVec.push_back(x);
		pointYVec.push_back(y);
	}

	int checkX = pointXVec[0];
	int	checkY = pointYVec[0];

	int checkCountX = 0;
	int checkCountY = 0;

	int theOtherX, theOtherY;

	for (int i = 1; i < 3; i++)
	{
		// �ٸ��ٸ� ����
		if (pointXVec[i] != checkX)
		{
			theOtherX = pointXVec[i];
		}
		// ���� �� ���ٸ�
		else
		{
			checkCountX++;
		}

		// �ٸ��ٸ� ����
		if (pointYVec[i] != checkY)
		{
			theOtherY = pointYVec[i];
		}
		// ���� �� ���ٸ�
		else
		{
			checkCountY++;
		}
	}

	int outputX;
	int outputY;
	if (checkCountX == 0)
	{
		outputX = checkX;
	}
	else
	{
		outputX = theOtherX;
	}

	if (checkCountY == 0)
	{
		outputY = checkY;
	}
	else
	{
		outputY = theOtherY;
	}

	cout << outputX << " " << outputY;

	return 0;
}