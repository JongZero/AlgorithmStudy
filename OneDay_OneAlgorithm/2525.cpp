#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a, b, c;
	std::cin >> a >> b >> c;

	b += c;

	// 60���� �Ѿ��ٸ�
	if (b >= 60)
	{
		while (true)
		{
			// 60���� �ȳ��� ������ �߰�
			if (b < 60)
			{
				break;
			}

			// 1�ð� �߰�
			a += 1;

			// 60�о� ����
			b -= 60;
		}
	}
	
	// 24�ð� �Ѿ��ٸ�
	if (a >= 24)
	{
		// 0���� �ٽ� ����
		a -= 24;
	}

	std::cout << a << " " << b;

	return 0;
}