#include <iostream>
#include <vector>
#include <string>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

struct TestWeight
{
public:
	TestWeight(int weight) : m_Weight(weight) {}

	int m_Weight = 44;
};

struct TestVertex
{
public:
	std::vector<TestWeight> m_Weight;
};

struct Test
{
	std::vector<TestVertex> m_TestVec;
	int m_Index = 0;
	char m_Char = 'a';
	std::string m_Name;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	Test* _test = new Test;
	_test->m_TestVec.push_back(TestVertex());
	_test->m_TestVec.front().m_Weight.push_back(TestWeight(1));
	_test->m_TestVec.front().m_Weight.push_back(TestWeight(2));
	_test->m_TestVec.front().m_Weight.push_back(TestWeight(3));

	_test->m_TestVec.push_back(TestVertex());
	_test->m_TestVec.push_back(TestVertex());
	_test->m_TestVec.push_back(TestVertex());
	_test->m_TestVec.back().m_Weight.push_back(TestWeight(4));
	_test->m_TestVec.back().m_Weight.push_back(TestWeight(5));

	_test->m_TestVec.push_back(TestVertex());

	_test->m_Name = "Test";

	delete _test;

	_CrtDumpMemoryLeaks();

	return 0;
}