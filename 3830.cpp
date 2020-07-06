#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

char o;
int N, M, a, b;
int parent[100001];
ll cost[100001], w;

int find(int x) {
	if(x == parent[x]) return x;
	else {
		int temp = find(parent[x]);
		cost[x] += cost[parent[x]];
		return parent[x] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(1) {
		cin >> N >> M;
		if(!N && !M) {return 0;}
		for(int i = 1; i <= N; i++) {parent[i] = i; cost[i] = 0;}
		for(int i = 0; i < M; i++){
			cin >> o;
			if(o == '!') {
				cin >> a >> b >> w;
				int l = find(a);
				int r = find(b);
				if(l != r){
					parent[l] = r;
					cost[l] = cost[b] - cost[a] + w;
				}
			}
			else {
				cin >> a >> b;
				int l = find(a);
				int r = find(b);
				if(l != r) cout << "UNKNOWN\n";
				else cout << cost[a]-cost[b] << "\n";
			}
		}
	}
	
	return 0;
}
