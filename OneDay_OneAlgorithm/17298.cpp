#include <iostream>
#include <vector>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	// ver 0.1
	// ���͸� ����� ��ȿ������ ����
	/*
	std::vector<int> _vec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> _vec[i];
	}

	for (int i = 0; i < n; i++)
	{
		int max = _vec[i];
		for (int j = i + 1; j < n; j++)
		{
			if (_vec[i] < _vec[j])
			{
				max = _vec[j];
				break;
			}
		}

		if (max == _vec[i])
		{
			std::cout << "-1 ";
		}
		else
		{
			std::cout << max << ' ';
		}
	}
	*/

	// ver 0.2
	// ������ ����� �ڱ� ������ �����鼭 üũ�Ѵ�.
	std::vector<int> _resultVec(n);	// ��� ����
	std::stack<int> _inputStack;	// ��ǲ���� ���� ���� ����
	std::stack<int> _rights;		// �� �����ʵ�
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;
		_inputStack.push(input);
	}

	// ������ ���鼭 �˻�
	int rightMax = -1;		// �����ʿ� �����鼭 ���� ū��
	int index = n - 1;
	while (!_inputStack.empty())
	{
		int top = _inputStack.top();
		_rights.push(top);

		// �� �������� ������ �۴ٸ�
		if (rightMax < top)
		{
			_resultVec[index] = -1;

			// ���� ������ ������ �߿� ���� ū �༮�� ����.
			rightMax = top;
		}
		// �� �������� ������ ũ�ٸ�
		else
		{
			// �� �༮�� ��� ���� ����
			_resultVec[index] = rightMax;
		}

		index--;
		_inputStack.pop();
	}
	
	for (int i = 0; i < n; i++)
	{
		std::cout << _resultVec[i] << ' ';
	}

	return 0;
}