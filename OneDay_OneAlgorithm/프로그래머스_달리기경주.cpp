#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;

	unordered_map<string, int> name_rank;
	unordered_map<int, string> rank_name;

	{
		int i = 0;
		for (const string& s : players) {
			name_rank[s] = i;
			rank_name[i] = s;
			++i;
		}
	}

	for (const string& s : callings) {

		int current_rank = name_rank[s];
		int next_rank = current_rank - 1;

		// swap
		string temp_name = rank_name[next_rank];

		rank_name[next_rank] = rank_name[current_rank];
		rank_name[current_rank] = temp_name;

		name_rank[s] = next_rank;
		name_rank[temp_name] = current_rank;
	}

	{
		int i = 0;
		for (const string& s : players) {
			answer.push_back(rank_name[i]);
			++i;
		}
	}

	return answer;
}