#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pa;
int n;
int scores[3];
pa times[3];

int prevM = -1;
int prevS = -1;

int mini;
int sec;

void addTime(int n)
{
	int addMin = mini - prevM;
	int addSec = sec - prevS;
	if (addSec < 0)
	{
		addMin--;
		addSec += 60;
	}
	times[n].first += addMin;
	times[n].second += addSec;
	if (times[n].second >= 60)
	{
		times[n].first++;
		times[n].second = times[n].second - 60;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int teamNum = 0;
		string time;
		cin >> teamNum >> time;
		
		int pos = time.find(":");
		string m = time.substr(0, pos);
		mini = stoi(m);
		string s = time.substr(pos + 1);
		sec = stoi(s);

		if (prevM != -1 && prevS != -1)
		{
			if (scores[1] > scores[2])
			{
				addTime(1);
			}
			else if (scores[1] < scores[2])
			{
				addTime(2);
			}
		}
		prevM = mini;
		prevS = sec;

		scores[teamNum]++;
	}

	mini = 48;
	sec = 0;
	if (scores[1] > scores[2])
	{
		addTime(1);
	}
	else if (scores[1] < scores[2])
	{
		addTime(2);
	}
	vector<string> ret;
	ret.push_back(to_string(times[1].first));
	ret.push_back(to_string(times[1].second));
	ret.push_back(to_string(times[2].first));
	ret.push_back(to_string(times[2].second));
	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i].size() < 2)
		{
			ret[i].insert(0, "0");
		}
		if (i == 2) cout << '\n';
		cout << ret[i];
		if (i % 2 == 0) cout << ":";
	}
}