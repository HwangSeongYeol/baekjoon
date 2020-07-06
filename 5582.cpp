#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001];
char A[4001], B[4001];
int As, Bs;
int ans = 0;
int main() {
	string temp;
	cin >> temp; As = temp.length();
	for(int i = 1; i <= As; i++) A[i] = temp[i-1];
	cin >> temp; Bs = temp.length();
	for(int i = 1; i <= Bs; i++) B[i] = temp[i-1];
	
	for(int i = 1; i <= As; i++) {
		for(int j = 1; j <= Bs; j++) {
			if(A[i]==B[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}		
		}
	}
	cout << ans;
	
	return 0;
}
