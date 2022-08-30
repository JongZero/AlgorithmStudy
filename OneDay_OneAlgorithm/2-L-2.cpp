#include <bits/stdc++.h>
using namespace std;

int n, prevTime = -1;
int score1, score2, time1, time2;

int timeStrToTimeInt(string timeStr)
{
	int m = stoi(timeStr.substr(0, 2));
	int s = stoi(timeStr.substr(3, 2));
	return m * 60 + s;
}

void addTime(int nowTime)
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

string timeIntToTimeStr(int time)
{
	string m = to_string(time / 60);
	string s = to_string(time % 60);
	if (m.size() < 2) m.insert(0, "0");
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
		string timeStr;
		cin >> team >> timeStr;
		int time = timeStrToTimeInt(timeStr);
		if (prevTime != -1)
		{
			addTime(time);
		}
		prevTime = time;
		if (team == 1) score1++;
		else score2++;
	}
	addTime(48 * 60);
	cout << timeIntToTimeStr(time1) << '\n';
	cout << timeIntToTimeStr(time2) << '\n';
}