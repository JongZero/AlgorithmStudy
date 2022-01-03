#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// <summary>
/// 메모리초과...
/// 클래스 생성하면 안될듯
/// </summary>

class Node
{
public:
	std::vector<Node*> m_Next;
};

// 1번 컴퓨터와 연결되어있는지 아닌지
std::map<Node*, bool> g_CheckConnectMap;

void Check(Node* node)
{
	for (int i = 0; i < node->m_Next.size(); i++)
	{
		Node* checkNode = node->m_Next[i];
		while (true)
		{
			if (checkNode == nullptr)
			{
				break;
			}

			// 연결되어있다고 표시
			if (g_CheckConnectMap[checkNode] == false)
				g_CheckConnectMap[checkNode] = true;

			if (checkNode->m_Next.size() > 0)
			{
				Check(checkNode);
			}

			checkNode = nullptr;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// 컴퓨터의 수
	int n = 0;
	cin >> n;

	// 컴퓨터들
	vector<Node*> nodeVec(n);

	for (int i = 0; i < n; i++)
	{
		nodeVec[i] = new Node();
	}

	// 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
	int connectCount = 0;
	cin >> connectCount;

	for (int i = 0; i < connectCount; i++)
	{
		int com1, com2;
		cin >> com1 >> com2;

		// 인덱스는 하나 씩 줄여서
		com1--;
		com2--;
		
		nodeVec[com1]->m_Next.push_back(nodeVec[com2]);
	}

	// 1번 컴퓨터와 연결된 컴퓨터의 수를 파악
	for (int i = 0; i < n; i++)
	{
		g_CheckConnectMap[nodeVec[i]] = false;
	}

	Check(nodeVec[0]);

	int count = 0;
	for (auto it : g_CheckConnectMap)
	{
		if (it.second == true)
		{
			count++;
		}
	}

	cout << count;

	for (int i = 0; i < n; i++)
	{
		delete nodeVec[i];
	}

	nodeVec.clear();
	g_CheckConnectMap.clear();

	return 0;
}