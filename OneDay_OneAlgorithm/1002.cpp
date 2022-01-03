#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		// �� ���� ������ ���� �������� ���ٸ� ���Ѵ��� ������ ��ģ��.
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << "\n";
			continue;
		}
		// �� ���� ������ ���� �������� �ٸ��ٸ� ������ �ʴ´�.
		else if (x1 == x2 && y1 == y2 && r1 != r2)
		{
			cout << 0 << "\n";
			continue;
		}

		// �� ���� ���� ������ �Ÿ��� ���Ѵ�.
		int distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
		int rPlus = pow(r1 + r2, 2);
		int rMinus = pow(r2 - r1, 2);

		// r1 + r2�� �Ÿ��� ���Ͽ� ������ �� ���� 1���� ��ġ��
		// r1 + r2�� �� ũ�� �� ���� 2���� ��ġ��
		// �Ÿ��� �� ũ�� �� ���� ��ġ�� �ʴ´�. ���� ������ 0, 1, 2�߿� �ϳ��� ���� ���̴�.
		if (rPlus > distance)
		{
			// �����ϴ� ���
			if (rMinus == distance)
			{
				cout << 1;
			}
			// �� ���� �� �� �ȿ� ���ϴ� ���
			else if (rMinus > distance)
			{
				cout << 0;
			}
			else
			{
				cout << 2;
			}
		}
		// �����ϴ� ���
		else if (rPlus == distance)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}

		cout << "\n";
	}

	return 0;
}