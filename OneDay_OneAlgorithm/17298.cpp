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

	// ver 0.2
	// 스택을 사용해 자기 왼쪽은 버리면서 체크한다.
	std::vector<int> _resultVec(n);	// 결과 저장
	std::stack<int> _inputStack;	// 인풋으로 들어온 수열 저장
	std::stack<int> _rights;		// 내 오른쪽들
	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;
		_inputStack.push(input);
	}

	// 스택을 비우면서 검사
	int rightMax = -1;		// 오른쪽에 있으면서 가장 큰것
	int index = n - 1;
	while (!_inputStack.empty())
	{
		int top = _inputStack.top();
		_rights.push(top);

		// 내 오른쪽이 나보다 작다면
		if (rightMax < top)
		{
			_resultVec[index] = -1;

			// 다음 원소의 오른쪽 중에 제일 큰 녀석은 나다.
			rightMax = top;
		}
		// 내 오른쪽이 나보다 크다면
		else
		{
			// 그 녀석을 결과 값에 저장
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