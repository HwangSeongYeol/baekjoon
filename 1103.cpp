#include <iostream>
#include <string>

using namespace std;

int N, M, ans;
int o[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
string m[51]; 
int v[51][51];
int dp[51][51];

int dfs(int x, int y) {
	if(y < 0 || N <= y || x < 0 || M <= x || m[y][x] == 'H') return 0;
	if(v[y][x]) {cout << "-1\n"; exit(0);}
	if(dp[y][x]) return dp[y][x];
	v[y][x] = 1;
	for(int i = 0; i < 4; i++){ 
		int num = m[y][x] - '0';
		int num = m[y][x] - '0';
		dp[y][x] = max(dp[y][x], dfs(x+o[i][0]*num, y+o[i][1]*num)+1);
	}
	v[y][x] = 0;	
	return dp[y][x];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> m[i];
	cout << dfs(0,0);
	return 0;
}
