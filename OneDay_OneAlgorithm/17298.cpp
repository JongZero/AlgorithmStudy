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
	// 벡터를 사용한 비효율적인 버전
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
	std::vector<int> _inputVec(n);		// 인풋으로 받은 숫자들
	std::vector<int> _resultVec(n);		// 결과 값
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		for (int j = 0; j < i; j++)
		{
			// NGE가 없는 숫자들만 검사
			if (_resultVec[j] != 0)
				continue;

			// 이전에 받았던 숫자들보다 내가 더 크다면 내가 그 숫자의 NGE가된다.
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
	std::stack<int> _stack;							// 인풋과 비교할 숫자들
	std::stack<int> _temp;
	std::vector<std::pair<int, int>> _resultVec;	// 결과를 저장

	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		// 결과를 0으로 초기화
		_resultVec.push_back(std::pair<int, int>(input, 0));

		// 스택의 사이즈만큼 돌면서 체크
		int size = _stack.size();
		for (int j = 0; j < size; j++)
		{
			int top = _stack.top();

			// 오른쪽이 더 크다면
			if (input > top)
			{
				// 키 값과 결과가 아직 입력되지 않았다면
				for (auto& it : _resultVec)
				{
					if (it.first == top && it.second == 0)
					{
						// 결과를 입력
						it.second = input;
						break;
					}
				}
			}
			// 오른쪽이 나보다 작으면 체크 필요X
			else
			{
				_temp.push(top);
			}

			_stack.pop();
		}

		// 체크했던 수들을 다음 번에도 체크하기 위해 다시 스택에 넣음
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
	std::stack<std::pair<int, int>> _stack;	// 인풋과 비교할 숫자들, 두 번째는 입력받은 순서
	std::vector<int> _resultVec(n);			// 결과를 저장

	int prev = 1000001;
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		// 바로 이전 숫자와 현재 숫자 비교해서 현재 숫자가 더 크다면
		if (prev < input)
		{
			// 스택을 돌면서 현재 숫자보다 작은 것들은 전부 빼주고 결과입력
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

		// 현재 숫자를 스택에 넣음 (다음 번에 입력되는 숫자와 체크 필요)
		_stack.push(std::pair<int, int>(input, i));
	}

	// 출력
	for (const auto& it : _resultVec)
	{
		// 결과 값이 없으면 -1
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