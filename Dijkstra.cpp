#include<iostream>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

class Dijkstra{
public:
	// graph initialization
	void initGraph(istream& in){
		string line;
		in.ignore();
		while(getline(in, line)){
			stringstream ss(line);
			string start, end;
			int weight;
			ss>>start>>end>>weight;
			graph[start].push_back(make_pair(end, weight));
			// record all of nodes
			allNodes.insert(start);
		}
		return;
	}

	// calculate the cost of each node from the start node
	// 
	void initCosts(string& start){
		// directly linked to start node
		for(auto item : graph[start]){
			costs[item.first] = item.second;
		}
		// indirectly linked to the start node
		// Let their value be INT_MAX
		for(auto item : allNodes){
			if(costs.find(item) == costs.end()){
				costs[item] = INT32_MAX;
			}
		}
		return;
	}

	// initizalize the parent of each node
	void initParents(string& start){
		parents[start] = "";
		for(auto item : graph[start])
			parents[item.first] = start;
		for(auto item : allNodes){
			if(parents.find(item) == parents.end())
				parents[item] = "";
		}
	}

	// find the node with the lowest cost
	string findLowestCostNode(void){
		string lowest_cost_node = "";
		int lowest_cost = INT32_MAX;
		for(auto cost : costs){
			if(!isContainNode(processed, cost.first) && cost.second<lowest_cost){
				lowest_cost = cost.second;
				lowest_cost_node = cost.first; 
			}
		}
		return lowest_cost_node;
	}
	
	// dijkstra algorithm
	void Run(string& start){
		string node = findLowestCostNode();
		int cur_cost;
		while(!node.empty()){
			cur_cost = costs[node];
			for(auto item : graph[node]){
				int new_cost = cur_cost + item.second;
				// find the shorter path, then update cost and parent
				if(costs[node] > new_cost){
					costs[node] = new_cost;
					parents[node] = item.first;
				}
			}
			processed.insert(node);
			node = findLowestCostNode();
		}
	}

private:
	using pp = pair<string, int>;
	unordered_map<string, vector<pp>> graph;
	unordered_map<string, int> costs;
	unordered_map<string, string> parents;
	unordered_set<string> processed;
	unordered_set<string> allNodes;
	int N_;

	inline bool isContainNode(unordered_set<string> s, string a){
		return (s.find(a) != s.end());
	}
};