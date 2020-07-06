#include <iostream>
#include <vector>
#define INF 0x7FFFFFFF

using namespace std;
int N, M, a, b, c;
int time[501];
int temp[501];
int v[501];
vector<vector<int>> routes;

int main() {
	cin >> N >> M;
	for(int i = 2; i <= N; i++) {
		time[i] = INF;
	}
	v[1] = 1;
	while(M--) {
		cin >> a >> b >> c;
		routes.push_back({a, b, c});
	}
	
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < routes.size(); j++) {
			if(v[routes[j][0]]) {
				v[routes[j][1]] = 1;
				if(time[routes[j][0]] + routes[j][2] < time[routes[j][1]])
					time[routes[j][1]] = time[routes[j][0]] + routes[j][2];
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		temp[i] = time[i] ;
	}
	
	for(int j = 0; j < routes.size(); j++) {
		if(v[routes[j][0]]) {
			v[routes[j][1]] = 1;
			if(time[routes[j][0]] + routes[j][2] < time[routes[j][1]])
				time[routes[j][1]] = time[routes[j][0]] + routes[j][2];
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(time[i] < temp[i]) {
			cout << -1;
			return 0;
		}
	}
	
	for(int i = 2; i <= N; i++) {
		if(time[i] != INF) cout << time[i] << "\n";
		else cout << "-1\n";
	}
	
	return 0;
}
