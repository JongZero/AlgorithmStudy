#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	// �ڿ��� n�� ���� ���� ������, �����ڰ� ���ٸ� 0�� ���
	int result = 0;

	// �ڿ����� �ּ� �������� �ִ�������� ���鼭
	for (int i = 1; i <= 1000000; i++)
	{
		// �� �ڿ�����
		int sum = i;

		// �ڿ����� ���ڸ��� ���� ��� ����
		string numStr = to_string(i);
		for (int j = 0; j < numStr.size(); j++)
		{
			// char to int
			sum += numStr[j] - '0';
		}

		// n�� ������ �������̴�.
		// ���� ���� �͸� ã���� �ǹǷ� ã�Ҵٸ� �� ���� ���� ���� ���̴�.
		if (sum == n)
		{
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}