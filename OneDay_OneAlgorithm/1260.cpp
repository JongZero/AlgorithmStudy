#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

std::vector<bool> isVisitedVec;
std::map<int, std::vector<int>> mInputMap;

// 재귀 방식
void DFS(int v)
{
	isVisitedVec[v] = true;
	std::cout << v << ' ';

	// 인풋받은게 있을 때 (간선이 있을 때, 갈 곳이 있을 때)
	if (mInputMap.count(v) > 0)
	{
		for (int j = 0; j < mInputMap[v].size(); j++)
		{
			// 아직 방문하지 않았다면, 방문
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

	int n = 0;	// 정점 개수
	int m = 0;	// 간선 개수
	int v = 0;	// 탐색 시작할 정점 번호

	std::cin >> n >> m >> v;

	std::map<int, bool> isAddMap;

	for (int i = 0; i < m; i++)
	{
		int start = 0;
		int end = 0;
		std::cin >> start >> end;

		// 서로 연결되어있음
		mInputMap[start].emplace_back(end);
		mInputMap[end].emplace_back(start);
	}
	
	for (auto& it : mInputMap)
	{
		sort(it.second.begin(), it.second.end());
	}

	// DFS
	isVisitedVec.resize(n + 1);	// 방문했는지

	// 재귀
	//DFS(v);

	// 스택 이용
	std::stack<int> dfsStack;

	dfsStack.push(v);

	while (!dfsStack.empty())
	{
		// 가장 위를 꺼내고 방문
		int top = dfsStack.top();
		dfsStack.pop();

		if (isVisitedVec[top] == false)
		{
			isVisitedVec[top] = true;
			std::cout << top << ' ';
		}

		// 거꾸로 돌아야함 (작은거부터 갈수있도록)
		for (int i = mInputMap[top].size() - 1; i >= 0; i--)
		{
			int node = mInputMap[top][i];

			// 방문한 적이 있다면 pass
			if (isVisitedVec[node] == true)
				continue;

			// 방문한 적이 없다면 stack에 넣음
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
		// 가장 앞을 꺼내고 방문
		int front = bfsQueue.front();
		bfsQueue.pop();

		for (int i = 0; i < mInputMap[front].size(); i++)
		{
			// 방문한 적이 있다면 pass
			if (isVisitedVec[mInputMap[front][i]] == true)
				continue;

			// 방문한 적이 없다면 queue에 넣음
			bfsQueue.push(mInputMap[front][i]);

			isVisitedVec[mInputMap[front][i]] = true;
		}
		
		std::cout << front << ' ';
		
	} while (!bfsQueue.empty());

	return 0;
}
