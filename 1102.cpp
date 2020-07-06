#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N, cost[16][16];
int now, P;
int dp[16][1<<16];
int ans = 987654321;
vector<int> possible;

int cal1 (int i) {
	int ret = 0;
	while(i != 0) {
		if(i&1) ret++;
		i >>= 1;
	}
	return ret;
}

int solve(int idx, int curState) {
	if(cal1(curState) >= P) return 0;
	int& ret = dp[idx][curState];
	if(ret != -1) return ret;
	ret = 987654321;
	for(int i = 0; i < N; i++) {
		if((curState & (1 << i)) == 0) {
			int nextState = curState | (1 << i);
			for(int j = 0; j < N; j++)
				if(nextState & (1 << j))
					ret = min(ret, solve(j, nextState)+cost[idx][i]);
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> cost[i][j]; //i에서j로 가는 비용. 
		}
	}
	string stemp;
	cin >> stemp;
	for(int i = 0; i < N; i++) {
		if(stemp[i] == 'Y'){
			now |= 1<<i;
			possible.push_back(i);
		}
	}
	cin >> P;
	memset(dp,-1,sizeof(dp));
	
	if(P==0) {
		cout << 0;
		return 0;
	}
	
	for(int temp : possible)
		ans = min(ans,solve(temp, now));
	
	
	if(ans == 987654321) cout << -1;
	else cout << ans;
	return 0;
}
