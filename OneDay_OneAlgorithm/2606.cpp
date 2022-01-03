#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// <summary>
/// �޸��ʰ�...
/// Ŭ���� �����ϸ� �ȵɵ�
/// </summary>

class Node
{
public:
	std::vector<Node*> m_Next;
};

// 1�� ��ǻ�Ϳ� ����Ǿ��ִ��� �ƴ���
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

			// ����Ǿ��ִٰ� ǥ��
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

	// ��ǻ���� ��
	int n = 0;
	cin >> n;

	// ��ǻ�͵�
	vector<Node*> nodeVec(n);

	for (int i = 0; i < n; i++)
	{
		nodeVec[i] = new Node();
	}

	// ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ��
	int connectCount = 0;
	cin >> connectCount;

	for (int i = 0; i < connectCount; i++)
	{
		int com1, com2;
		cin >> com1 >> com2;

		// �ε����� �ϳ� �� �ٿ���
		com1--;
		com2--;
		
		nodeVec[com1]->m_Next.push_back(nodeVec[com2]);
	}

	// 1�� ��ǻ�Ϳ� ����� ��ǻ���� ���� �ľ�
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