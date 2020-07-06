#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans = 2000000, S;
int arr[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> S;
	for(int i=0; i<N; i++){cin >> arr[i];}
	int l=0, r=0;
	int s=arr[0];
	while(l<=r && r < N){
		if(s<S){s+=arr[++r];}
		else if(s >= S) {
			ans = min(ans, r-l+1);
			s-=arr[l++];
		}
	}
	if(ans == 2000000) cout << 0;
	else cout << ans;
	return 0;
}
