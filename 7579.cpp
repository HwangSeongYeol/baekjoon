#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int c[101], m[101];
int dp[101][10001];
int ans = 987654321;

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> m[i];
	for(int i = 1; i <= N; i++) cin >> c[i];
	
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= 10000; j++) {
			if(j-c[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]]+m[i]);
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(dp[i][j] >= M)
				ans = min(ans, j);
		}
	}
	cout << ans;
	
	return 0;
}
