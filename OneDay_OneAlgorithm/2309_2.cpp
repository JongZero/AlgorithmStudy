/*
#include <iostream>
#include <vector>
#include <algorithm>

const int Max = 100;

void sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// �ּҸ� ã�´�.
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

		// �ּҸ� �� ��ġ�� �ִ´�.
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
	
	// �Է� �ޱ�
	for (int i = 0; i < MaxCount; i++)
	{
		std::cin >> arr[i];
	}
	
	// Brute Force
	/*
	// �� ���� ���� ���� ���Ѵ�.
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

	// ���� ����
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
#include <algorithm> //sort�˰����� ����ϱ� ����.
using namespace std;
int cnt = 0, sum = 0, arr[10], ch[10];

void DFS(int L) 
{
	//L�� DFS Ʈ���� ����(Ȥ�� ����)�� �ǹ��մϴ�.
	if (cnt == 7) 
	{
		if (sum == 100) 
		{
			//cnt(count�� ����)�� 7�� ��, ���� 100�� ��찡 ����� �ؾ��ϴ� ����Դϴ�.
				for (int i = 1; i <= 9; i++)
					if (ch[i] == 1)
						cout << arr[i] << "\n";
			exit(0); //������ �κ��Դϴ�.
				//�������� '������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.'��� �߰�, 
				//'�ϰ� �����̸� ã�� �� ���� ���� ����.'��� �߱� ������
				//���� 100�� ��찡 ������ �����ϰ�,
				//���� ��� �߿� ó�� �����ϴ� ��� �ѹ��� ����ϸ� �Ǳ� ������
				//#exit(0)�� �̿��ؼ� ����Լ��� ������ �������;��մϴ�.
				//�޸� �̾߱��ϸ�, return���� ���������� ���� �ƴ϶�,
				//stack�� �����ִ� ��� �Լ��� �����ؾ� �մϴ�.
				//�׷��� �� Ǯ���� ���, exit(0)�� �̿��ؼ� �������;� ������ �ذ�˴ϴ�.
		}
		return;
	}

	if (L == 10)
		//DFS�� ���̰�(L) 9�� �Ѿ�� ���, return�ؼ� �������ؾ� DFS�� ������ �ݺ����� �ʽ��ϴ�.
		return;
	else 
	{
		sum += arr[L];
		ch[L] = 1;
		cnt++;
		DFS(L + 1);

		//ch[L](check�� ���ڷ�, ���� �޾Ƽ� ���ߴ��� �� ���ߴ����� 0, 1�� �����մϴ�.
		//sum�� ��� �����ְ�
		//sum�� ������ ������ cnt++�� �ؼ� Ȯ���� '������ Ű'�� �� ������ �����մϴ�.

		sum -= arr[L];
		ch[L] = 0;
		cnt--;
		DFS(L + 1);
		//Ű�� ������ ���� ���� ����Դϴ�.
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