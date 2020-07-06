#include <iostream>

using namespace std;
long long dp[95], n;
void f(int n) {
	dp[n] = dp[n-1]+dp[n-2];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dp[0] = 0; dp[1] = 1;
	for(int i = 2; i < 91; i++) f(i);
	cout << dp[n] << "\n";
	return 0;
}
