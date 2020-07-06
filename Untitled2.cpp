#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
char o;
int N, M, a, b, w;
vector<string> ans;
int parent[100001];
int cost[100001];

int find(int x) {
	if(x == parent[x]) return x;
	else {return parent[x] = find(parent[x]);}
}

void uni(int x, int y) {
	x = find(x); y = find(y);
	if(x != y) {parent[y] = x;}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(1) {
		cin >> N >> M;
		if(!N && !M)break;
		for(int i = 1; i <= N; i++){parent[i] = i;}
		for(int i = 0; i < M; i++){
			cin >> o;
			if(o == '!') {
				cin >> a >> b >> w;
				if(a > b) {
					swap(a,b); w = -w;
				}
				if(find(a) != find(b)) {
					cost[find(b)] = cost[find(a)] + w;
					uni(a, b);
				}	
			}
			else {
				cin >> a >> b;
				if(find(a) != find(b)) ans.push_back("UNKNOWN");
				else {
					ans.push_back(to_string(cost[b]-cost[a]));
				}
			}
		}
	}
	for(string s : ans) cout << s << "\n";

	return 0;
}
