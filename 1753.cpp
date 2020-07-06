#include <iostream>
#include <vector>
#include <queue>
#define INF 0x7FFFFFFF
using namespace std;


vector<pair<int,int>> graph[20001];
int V, E, K, u, v, w;
priority_queue<pair<int,int>> pq;
int weight[20001];

int main(){
	cin >> V >> E >> K;
	
	for(int i = 1; i <= V; i++) weight[i] = INF;
	weight[K] = 0;
	
	for(int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
	}
	
	pq.push({0,K});
	
	while(!pq.empty()) {
		int cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		for(pair<int,int> next : graph[pos]) {
			int cost_next = next.second;
			int pos_next = next.first;
			if (-cost + cost_next < weight[pos_next]) {
				weight[pos_next] = -cost + cost_next;
				pq.push({-weight[pos_next], pos_next});
			}
		}
	}
	
	for(int i = 1; i <= V; i++) if(weight[i] != INF) cout << weight[i] << "\n"; else cout << "INF\n";
	
	return 0;
}
