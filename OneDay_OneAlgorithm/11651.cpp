#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> nums1, pair<int, int> nums2)
{
	if (nums1.second == nums2.second)
		return nums1.first < nums2.first;

	return nums1.second < nums2.second;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t = 0;
	cin >> t;

	vector< pair<int, int> > numsVec(t);

	for (int i = 0; i < t; i++)
	{
		int n1, n2 = 0;
		cin >> n1 >> n2;

		pair<int, int> nums(n1, n2);
		numsVec[i] = nums;
	}

	sort(numsVec.begin(), numsVec.end(), compare);

	for (const auto& it : numsVec)
	{
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}