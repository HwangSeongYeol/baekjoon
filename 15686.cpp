#include <iostream>
#include <queue> 
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M, cs;
vector<vector<int>> h, c;
int ans = 100000;
int v[14];

void dfs(int idx, int now) {
	if(now > c.size()) return;
	if(idx == M){
		int ret = 0;
		for(int i = 0; i < h.size(); i++) {
			int min = 200;
			for(int j = 0; j < c.size(); j++) {
				if(v[j]){
					int cd = abs(c[j][0]-h[i][0])+abs(c[j][1]-h[i][1]);
					if(cd < min) min = cd;
				}
			}
			ret += min;
		}
		if(ret < ans) {
			ans = ret;
		}
		return;
	}
	v[now] = 1;
	dfs(idx+1, now+1);
	v[now] = 0;
	dfs(idx, now+1);
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int temp;
	cin >> N >> M;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		cin >> temp;
		if(temp == 1) h.push_back({i, j});
		else if(temp == 2) c.push_back({i, j});
	}
	
	dfs(0,0);
	
	cout << ans << "\n";
	return 0;
}
