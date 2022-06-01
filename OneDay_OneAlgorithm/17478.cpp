#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n = 0;

string Table[5] = { "\"����Լ��� ������?\"\n", 
		"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
		"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
		"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
		"��� �亯�Ͽ���.\n" };

void RecursiveFunc(int count, int underBarCount)
{
	if (n >= count)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < underBarCount; j++)
			{
				cout << '_';
			}

			cout << Table[i];
		}

		RecursiveFunc(count + 1, underBarCount + 4);

		for (int j = 0; j < underBarCount; j++)
		{
			cout << '_';
		}
		cout << Table[4];
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	RecursiveFunc(0, 0);

	return 0;
}