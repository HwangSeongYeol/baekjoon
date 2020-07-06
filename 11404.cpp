#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int N, M, a, b, c;
int cost[101][101];

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i!=j) cost[i][j] = MAX;
		}
	}
	
	while(M--) {
		cin >> a >> b >> c;
		
		cost[a][b] = min(c, cost[a][b]);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = 1; k <= N; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(cost[i][j]==MAX) cout << "0 ";
			else cout << cost[i][j] << " ";
		} cout << "\n";
	}
	return 0;
}
