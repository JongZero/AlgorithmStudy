#include <iostream>
using namespace std;

// �� ������ �Է� ������ "�Է��� ���� 0 0 ���� �־�����"���� ������ ������,
// "ù ��° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����"���� ������ �����ϴ�.
// ��, �� �������� �Է��� �������� �˱� ���ؼ��� �� �̻� �Է��� ����(End of file, EOF)�� �ľ��ϴ� ����� ������ ����Դϴ�.

int main()
{
	while (true)
	{
		int a = 0, b = 0;

		cin >> a >> b;

		if (cin.eof())
			break;

		cout << a + b << endl;
	}

	return 0;
}