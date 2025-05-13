#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	unordered_map<string, std::unordered_set<string>> id_map;
	unordered_map<string, std::unordered_set<string>> report_map;

	for (int i = 0; i < report.size(); ++i) {
		string s = report[i];
		int pos = s.find(' ');

		string id = s.substr(0, pos);
		string report_id = s.substr(pos + 1, s.size());

		//cout << "id: " << id << " " << "report_id: " << report_id << "\n";

		id_map[id].insert(report_id);
		report_map[report_id].insert(id);
	}

	for (const string& s : id_list) {
		int ret = 0;
		for (const string& id : id_map[s]) {
			if (report_map[id].size() >= k) {
				ret++;
			}
		}
		answer.push_back(ret);
	}

	return answer;
}