#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int h = 0; // ȣ���� ���� ����
		int w = 0; // ȣ���� ���� ����
		int n = 0; // �� ��° �մ�����

		cin >> h >> w >> n;

		// 1 ~ 6
		if (n <= h)
		{
			string strN = to_string(n);
			strN += "01";

			cout << strN << "\n";
		}
		// 01ȣ�� �ƴϴ�. �Ѿ��.
		else
		{
			// 02ȣ���� �����Ѵ�.
			int startW = 2;

			// n - h�ؼ� h���� ������ �� ���� �ִ� ���̴�.
			// 10 - 6
			int checkN = n - h;

			while (true)
			{
				if (checkN <= h)
				{
					break;
				}
				else
				{
					// ��� ���� ����(���� ����)��ŭ ���ָ鼭 ��� ���� �ִ��� ã�´�.
					checkN -= h;

					// 03ȣ, 04ȣ, 05ȣ...
					startW++;
				}
			}

			string strN = to_string(checkN);

			// ���� �ڸ��� ��� �׳� ���δ�.
			if (startW >= 10)
			{
				strN += to_string(startW);
			}
			// ���� �ڸ��� ��� 0�� ���δ�.(01, 02, 03...)
			else
			{
				strN += "0";
				strN += to_string(startW);
			}

			cout << strN << "\n";
		}
	}
	
	return 0;
}