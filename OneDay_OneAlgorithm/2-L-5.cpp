#include <bits/stdc++.h>
using namespace std;

int n, score1, score2, time1, time2;
int prevTime;

int timeStrToTimeInt(string timeStr)
{
	int m = stoi(timeStr.substr(0, 2));
	int s = stoi(timeStr.substr(3));
	return m * 60 + s;
}

void checkTime(int time)
{
	if (score1 > score2)
	{
		time1 += time - prevTime;
	}
	else if (score1 < score2)
	{
		time2 += time - prevTime;
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
		checkTime(time);
		prevTime = time;
		if (team == 1) score1++;
		else score2++;
	}
	checkTime(60 * 48);
	cout << timeIntToTimeStr(time1) << '\n';
	cout << timeIntToTimeStr(time2);
}