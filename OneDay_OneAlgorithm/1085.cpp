#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> distances;
	
	// (x,y) ~ (0,0)
	distances.push_back(x);
	distances.push_back(y);

	// (x ~ w), (y ~ h)
	distances.push_back(w - x);
	distances.push_back(h - y);

	int min = 1000;
	for (int i = 0; i < distances.size(); i++)
	{
		if (distances[i] < min)
		{
			min = distances[i];
		}
	}

	cout << min;

	return 0;
}