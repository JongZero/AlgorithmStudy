#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		nums.push_back(t);
	}
	sort(nums.begin(), nums.end(), greater<int>());
	cout << nums[k - 1];
}