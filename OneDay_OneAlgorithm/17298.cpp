#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

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

	/*
	// ver 0.2
	std::vector<int> _inputVec(n);		// ��ǲ���� ���� ���ڵ�
	std::vector<int> _resultVec(n);		// ��� ��
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		for (int j = 0; j < i; j++)
		{
			// NGE�� ���� ���ڵ鸸 �˻�
			if (_resultVec[j] != 0)
				continue;

			// ������ �޾Ҵ� ���ڵ麸�� ���� �� ũ�ٸ� ���� �� ������ NGE���ȴ�.
			if (_inputVec[j] < input)
			{
				_resultVec[j] = input;
			}
		}

		_inputVec[i] = input;
	}

	for (int i = 0; i < n; i++)
	{
		if (_resultVec[i] == 0)
			std::cout << "-1\n";
		else
			std::cout << _resultVec[i] << "\n";
	}
	*/

	// ver 0.3
	/*
	std::stack<int> _stack;							// ��ǲ�� ���� ���ڵ�
	std::stack<int> _temp;
	std::vector<std::pair<int, int>> _resultVec;	// ����� ����

	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		// ����� 0���� �ʱ�ȭ
		_resultVec.push_back(std::pair<int, int>(input, 0));

		// ������ �����ŭ ���鼭 üũ
		int size = _stack.size();
		for (int j = 0; j < size; j++)
		{
			int top = _stack.top();

			// �������� �� ũ�ٸ�
			if (input > top)
			{
				// Ű ���� ����� ���� �Էµ��� �ʾҴٸ�
				for (auto& it : _resultVec)
				{
					if (it.first == top && it.second == 0)
					{
						// ����� �Է�
						it.second = input;
						break;
					}
				}
			}
			// �������� ������ ������ üũ �ʿ�X
			else
			{
				_temp.push(top);
			}

			_stack.pop();
		}

		// üũ�ߴ� ������ ���� ������ üũ�ϱ� ���� �ٽ� ���ÿ� ����
		while (!_temp.empty())
		{
			int top = _temp.top();
			_stack.push(top);
			_temp.pop();
		}

		_stack.push(input);
	}

	for (const auto& it : _resultVec)
	{
		if (it.second == 0)
		{
			std::cout << "-1 ";
		}
		else
		{
			std::cout << it.second << ' ';
		}
	}
	*/

	/// ver 0.4
	std::stack<std::pair<int, int>> _stack;	// ��ǲ�� ���� ���ڵ�, �� ��°�� �Է¹��� ����
	std::vector<int> _resultVec(n);			// ����� ����

	int prev = 1000001;
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		// �ٷ� ���� ���ڿ� ���� ���� ���ؼ� ���� ���ڰ� �� ũ�ٸ�
		if (prev < input)
		{
			// ������ ���鼭 ���� ���ں��� ���� �͵��� ���� ���ְ� ����Է�
			while (!_stack.empty())
			{
				std::pair<int, int> top = _stack.top();

				if (top.first >= input)
					break;

				_resultVec[top.second] = input;
				_stack.pop();
			}
		}
		else
		{
			prev = input;
		}

		// ���� ���ڸ� ���ÿ� ���� (���� ���� �ԷµǴ� ���ڿ� üũ �ʿ�)
		_stack.push(std::pair<int, int>(input, i));
	}

	// ���
	for (const auto& it : _resultVec)
	{
		// ��� ���� ������ -1
		if (it == 0)
		{
			std::cout << "-1 ";
		}
		else
		{
			std::cout << it << ' ';
		}
	}

	return 0;
}