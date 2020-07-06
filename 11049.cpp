#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, row, col;
struct m {
	int r, c;
}mat[501];
int dp[501][501];

int func(int x, int y) {
	if (x == y) return 0;
	int& ret = dp[x][y];
	if(ret != -1) return ret;
	
	int mm = 0x7FFFFFFF;
	
	for(int k = x; k < y; k++) {
		mm = min(mm, func(x,k) + func(k+1,y) + mat[x].r*mat[k].c*mat[y].c);
	}
	
	return ret = mm;
}

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> row >> col;
		mat[i] = {row, col};
	}
	
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= N; j++)
			dp[i][j] = -1;
			
	cout << func(1, N);
	
	return 0;
}
