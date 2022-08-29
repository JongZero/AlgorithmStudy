#include <bits/stdc++.h>
using namespace std;

int n, score1, score2, time1, time2;
int prevTime, nowTime;

int timeToInt(string timeS)
{
	int m = stoi(timeS.substr(0, 2));
	int s = stoi(timeS.substr(3, 2));
	return (m * 60) + s;
}

void calcTime()
{
	if (score1 > score2)
	{
		time1 += (nowTime - prevTime);
	}
	else if (score1 < score2)
	{
		time2 += (nowTime - prevTime);
	}
}

string getRetTime(int time)
{
	string m = to_string(time / 60);
	if (m.size() < 2) m.insert(0, "0");
	string s = to_string(time % 60);
	if (s.size() < 2) s.insert(0, "0");
	return m + ":" + s;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int team;
		string timeS;
		cin >> team >> timeS;
		nowTime = timeToInt(timeS);

		if (i != 0)
		{
			calcTime();
		}

		prevTime = nowTime;

		if (team == 1) score1++;
		else score2++;
	}
	nowTime = 48 * 60;
	calcTime();
	cout << getRetTime(time1) << "\n";
	cout << getRetTime(time2) << "\n";
}