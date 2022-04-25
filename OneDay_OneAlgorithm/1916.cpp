#include <iostream>
#include <vector>
#include <stack>

struct Bus
{
	int startCityNum = 0;	// ��� ���� ��ȣ
	int endCityNum = 0;		// ���� ���� ��ȣ
	int cost = 0;			// ������ ���
	bool isUsed = false;	// ���Ǿ�����?
};

int n = 0;
int m = 0;

std::vector<Bus> busVec(m);

int problemStart = 0;
int problemEnd = 0;

unsigned long long resultMin = 100000 * 100000;

void Func(int start, int cost)
{
	if (start == problemEnd)
	{
		if (cost < resultMin)
		{
			resultMin = cost;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			// ������ ������ �ʾҰ�, ��� ������ �������
			if (busVec[i].isUsed == false && busVec[i].startCityNum == start)
			{
				// ����ϰ�
				busVec[i].isUsed = true;

				cost += busVec[i].cost;

				// ������� ���� (������������)
				Func(busVec[i].endCityNum, cost);

				// ����
				busVec[i].isUsed = false;

				cost -= busVec[i].cost;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n;
	std::cin >> m;

	busVec.resize(m);

	for (int i = 0; i < m; i++)
	{
		std::cin >> busVec[i].startCityNum >> busVec[i].endCityNum >> busVec[i].cost;
	}

	// ���ؾ��ϴ� ���ۺ��� ��
	std::cin >> problemStart >> problemEnd;

	// ���� ����
	//Func(problemStart, 0);

	// ���� �����ʰ� ȿ�� ���ϱ�
	/*
	int result = 0;
	int start = problemStart;
	std::stack<Bus> busStack;	// �̿��� ������
	int tempIndex = 0;
	while (start < problemEnd)
	{
		int tempMax = -100000;
		for (int j = tempIndex; j < m; j++)
		{
			if (start == busVec[j].startCityNum)
			{
				// ���� �Ÿ��� ����� ��
				int dist = busVec[j].endCityNum - busVec[j].startCityNum;

				int temp = dist - busVec[j].cost;

				if (temp > tempMax)
				{
					tempMax = temp;
					tempIndex = j;
				}
			}
			else if (start < busVec[j].startCityNum)
				break;
		}

		Bus _bus = busVec[tempIndex];
		result += _bus.cost;
		start = _bus.endCityNum;
	}

	std::cout << result;
	*/



	return 0;
}