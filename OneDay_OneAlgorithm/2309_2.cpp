/*
#include <iostream>
#include <vector>
#include <algorithm>

const int Max = 100;

void sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// 최소를 찾는다.
		int min = Max;
		int minIndex = 0;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}

		// 최소를 제 위치에 넣는다.
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

/*
void Func(int arr[], int n, )
{

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	const int MaxCount = 9;

	int arr[MaxCount];
	
	// 입력 받기
	for (int i = 0; i < MaxCount; i++)
	{
		std::cin >> arr[i];
	}
	
	// Brute Force
	/*
	// 두 명을 빼고 합을 구한다.
	int sum = 0;
	for (int i = 0; i < MaxCount; i++)
	{
		for (int j = 0; j < MaxCount; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (int k = 0; k < MaxCount; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}

				sum += arr[k];
			}

			if (sum == 100)
			{
				arr[i] = 0;
				arr[j] = 0;
				break;
			}

			sum = 0;
		}

		if (sum == 100)
		{
			break;
		}
	}

	sort(arr, MaxCount);

	for (int i = 0; i < MaxCount; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		std::cout << arr[i] << '\n';
	}

	// 순열 응용
	std::vector<int> p(2);
	std::vector<int> seq;

	
	int num;
	int sum;

	for (int i = 0; i < 9; i++) {
		std::cin >> num;
		seq.push_back(num);
		if (i < 7) {
			p.push_back(1);
		}
	}

	sort(seq.begin(), seq.end());

	do {
		sum = 0;

		for (int i = 0; i < 9; i++) {
			if (p[i]) {
				sum += seq[i];
			}
		}

		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (p[i]) {
					std::cout << seq[i] << '\n';
				}
			}
			return 0;
		}

	} while (next_permutation(p.begin(), p.end()));

	return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> //sort알고리즘을 사용하기 위함.
using namespace std;
int cnt = 0, sum = 0, arr[10], ch[10];

void DFS(int L) 
{
	//L은 DFS 트리의 레벨(혹은 깊이)를 의미합니다.
	if (cnt == 7) 
	{
		if (sum == 100) 
		{
			//cnt(count의 약자)가 7일 때, 합이 100인 경우가 출력을 해야하는 경우입니다.
				for (int i = 1; i <= 9; i++)
					if (ch[i] == 1)
						cout << arr[i] << "\n";
			exit(0); //주의할 부분입니다.
				//문제에서 '가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.'라고 했고, 
				//'일곱 난쟁이를 찾을 수 없는 경우는 없다.'라고 했기 때문에
				//합이 100인 경우가 무조건 존재하고,
				//여러 경우 중에 처음 등장하는 경우 한번만 출력하면 되기 때문에
				//#exit(0)를 이용해서 재귀함수를 완전히 빠져나와야합니다.
				//달리 이야기하면, return으로 빠져나오는 것이 아니라,
				//stack에 남아있는 모든 함수를 종료해야 합니다.
				//그래서 제 풀이의 경우, exit(0)를 이용해서 빠져나와야 문제가 해결됩니다.
		}
		return;
	}

	if (L == 10)
		//DFS의 깊이가(L) 9를 넘어서는 경우, return해서 마무리해야 DFS가 무한히 반복되지 않습니다.
		return;
	else 
	{
		sum += arr[L];
		ch[L] = 1;
		cnt++;
		DFS(L + 1);

		//ch[L](check의 약자로, 값을 받아서 더했는지 안 더했는지를 0, 1로 구분합니다.
		//sum에 계속 더해주고
		//sum에 더해줄 때마다 cnt++을 해서 확인한 '난쟁이 키'가 몇 개인지 저장합니다.

		sum -= arr[L];
		ch[L] = 0;
		cnt--;
		DFS(L + 1);
		//키를 더하지 않을 때의 경우입니다.
	}
}

int main(int argc, const char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	for (int i = 1; i <= 9; i++)
		cin >> arr[i];
	sort(arr + 1, arr + 10);
	DFS(1);
	return 0;
}