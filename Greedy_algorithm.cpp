#include<iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

// always select the local optimal solution

class Solution{
public:
	Solution(){}
	~Solution(){}
	// find the least number of stations that can cover all states
	unordered_set<string> findLeastStations(unordered_map<string, unordered_set<string>>& stations, 
		unordered_set<string>& states_needed){
		unordered_set<string> final_stations;

		while(!states_needed.empty()){
			string best_station;
			unordered_set<string> states_covered = {};
			unordered_set<string>::iterator it;
			for(auto& station_attr : stations){
				unordered_set<string> covered = {};
				// calculate the intersection
				for (auto item : station_attr.second) {
					if (states_needed.find(item) != states_needed.end())
						covered.insert(item);
				}

				if(covered.size() > states_covered.size())
				{
					best_station = station_attr.first;
					states_covered = covered;
				}
			}
			final_stations.insert(best_station);
			for(auto item : states_covered)
				states_needed.erase(states_needed.find(item));
		}
		return final_stations;
	}
private:
	// all states needed covered
	unordered_set<string> states_needed;
	// all avaliable stations and the corresponding states covered 
	unordered_map<string, unordered_set<string>> stations;
};


// int main(void){
// 	Solution sol;
// 	unordered_map<string, unordered_set<string>> stations;
// 	unordered_set<string> states{"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
// 	stations["kone"].insert("id");
// 	stations["kone"].insert("nv");
// 	stations["kone"].insert("ut");
// 	stations["ktwo"].insert("wa");
// 	stations["ktwo"].insert("id");
// 	stations["ktwo"].insert("mt");
// 	stations["kthree"].insert("or");
// 	stations["kthree"].insert("nv");
// 	stations["kthree"].insert("ca");
// 	stations["kfour"].insert("nv");
// 	stations["kfour"].insert("az");
// 	stations["kfive"].insert("ca");
// 	stations["kfive"].insert("az");

// 	unordered_set<string> res;
// 	res = sol.findLeastStations(stations, states);
// 	for(auto item : res)
// 		cout<<item<<endl;
// 	return 0;
// }