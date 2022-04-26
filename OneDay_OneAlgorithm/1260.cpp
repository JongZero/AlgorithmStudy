#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

std::vector<bool> isVisitedVec;
std::map<int, std::vector<int>> mInputMap;

// ��� ���
void DFS(int v)
{
	isVisitedVec[v] = true;
	std::cout << v << ' ';

	// ��ǲ������ ���� �� (������ ���� ��, �� ���� ���� ��)
	if (mInputMap.count(v) > 0)
	{
		for (int j = 0; j < mInputMap[v].size(); j++)
		{
			// ���� �湮���� �ʾҴٸ�, �湮
			int visit = mInputMap[v][j];

			if (isVisitedVec[visit] == true)
				continue;

			DFS(visit);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;	// ���� ����
	int m = 0;	// ���� ����
	int v = 0;	// Ž�� ������ ���� ��ȣ

	std::cin >> n >> m >> v;

	std::map<int, bool> isAddMap;

	for (int i = 0; i < m; i++)
	{
		int start = 0;
		int end = 0;
		std::cin >> start >> end;

		// ���� ����Ǿ�����
		mInputMap[start].emplace_back(end);
		mInputMap[end].emplace_back(start);
	}
	
	for (auto& it : mInputMap)
	{
		sort(it.second.begin(), it.second.end());
	}

	// DFS
	isVisitedVec.resize(n + 1);	// �湮�ߴ���

	// ���
	//DFS(v);

	// ���� �̿�
	std::stack<int> dfsStack;

	dfsStack.push(v);

	while (!dfsStack.empty())
	{
		// ���� ���� ������ �湮
		int top = dfsStack.top();
		dfsStack.pop();

		if (isVisitedVec[top] == false)
		{
			isVisitedVec[top] = true;
			std::cout << top << ' ';
		}

		// �Ųٷ� ���ƾ��� (�����ź��� �����ֵ���)
		for (int i = mInputMap[top].size() - 1; i >= 0; i--)
		{
			int node = mInputMap[top][i];

			// �湮�� ���� �ִٸ� pass
			if (isVisitedVec[node] == true)
				continue;

			// �湮�� ���� ���ٸ� stack�� ����
			dfsStack.push(node);
		}
	} 




	isVisitedVec.clear();
	isVisitedVec.resize(n + 1);

	std::cout << '\n';

	// BFS
	std::queue<int> bfsQueue;

	bfsQueue.push(v);
	isVisitedVec[v] = true;
	int front = v;

	do 
	{
		// ���� ���� ������ �湮
		int front = bfsQueue.front();
		bfsQueue.pop();

		for (int i = 0; i < mInputMap[front].size(); i++)
		{
			// �湮�� ���� �ִٸ� pass
			if (isVisitedVec[mInputMap[front][i]] == true)
				continue;

			// �湮�� ���� ���ٸ� queue�� ����
			bfsQueue.push(mInputMap[front][i]);

			isVisitedVec[mInputMap[front][i]] = true;
		}
		
		std::cout << front << ' ';
		
	} while (!bfsQueue.empty());

	return 0;
}
