#include <iostream>
#include <limits.h>
using namespace std;

/// 1712

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	// �� �� �Ǹź���� �� �� �����뺸�� Ŀ�� ���ͺб����� �߻� �����ϴ�.
	if (B < C)
	{
		/// Mark 1 �ݺ��� ���
		/// �ð��ʰ��� Ʋ���ٰ� ����
		/*
		// ���ͺб����� �Ѵ� ��Ʈ�� �Ǹŷ�
		unsigned long long n = 0;

		// �ʱ� ���� ���� ����
		int k = A + B;
		n = k / C;

		for (unsigned long long i = n; i < ULLONG_MAX; i++)
		{
			// ��Ʈ���� �����ϴ� �� ���
			unsigned long long d = A + (B * i);

			// ��Ʈ���� �Ǹ��� ���� �� ����
			unsigned long long totalR = C * i;

			// �� ��� ���� �� ������ Ŭ ��
			if (d < totalR)
			{
				// ���� ����
				n = i;
				break;
			}
		}
		*/

		/// Mark2 �ݺ��� ��� X
		/// ����1�� ����3�� ������ �߰�
		/// �̸� ���� ������ �����ؼ� ����
		
		// ���ͺб����� �Ѵ� ��Ʈ�� �Ǹŷ�
		unsigned int n = 0;
		n = A / (C - B) + 1;

		cout << n;
	}
	else
	{
		cout << -1;
	}	

	return 0;
}