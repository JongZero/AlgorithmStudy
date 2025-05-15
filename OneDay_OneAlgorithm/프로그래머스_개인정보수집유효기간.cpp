#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

enum
{
	YEAR,
	MONTH,
	DAY,
	COUNT,
};

vector<int> parse(string s)
{
	vector<int> ret(COUNT);

	ret[YEAR] = stoi(s.substr(0, 4));
	ret[MONTH] = stoi(s.substr(5, 2));
	ret[DAY] = stoi(s.substr(8, 2));

	return ret;
}

int get_sum(vector<int> parse)
{
	int year = parse[YEAR];
	int month = parse[MONTH];
	int day = parse[DAY];

	int sum = ((year - 1) * 12 * 28) + ((month - 1) * 28) + (day);
	return sum;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	vector<int> today_parse = parse(today);
	int today_sum = get_sum(today_parse);

	unordered_map<string, int> term_map;

	for (const string& s : terms) {
		int pos = s.find(" ");
		string term = s.substr(0, pos);
		string month = s.substr(pos + 1, s.size());
		term_map[term] = stoi(month);
	}

	int i = 1;
	for (const string& s : privacies) {
		int pos = s.find(" ");
		string start_day = s.substr(0, pos);
		string term = s.substr(pos + 1, s.size());

		vector<int> start_parse = parse(start_day);
		int add_month = term_map[term];

		int year = start_parse[YEAR];
		int month = start_parse[MONTH];
		int day = start_parse[DAY];

		// month
		month += add_month;
		while (month > 12) {
			year++;
			month -= 12;
		}

		// day
		day--;
		if (day <= 0) {
			month--;
			day = 28;   // 모든 달은 28일까지 있다고 가정

			if (month <= 0) {
				year--;
				month = 12;
			}
		}

		int sum = get_sum({ year, month, day });

		if (today_sum > sum) {
			answer.push_back(i);
		}

		++i;
	}

	return answer;
}