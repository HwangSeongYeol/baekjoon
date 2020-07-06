#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long ans;
int a[4001],b[4001],c[4001],d[4001],ab[16000001],cd[16000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		long long ta,tb,tc,td;
		cin >> ta >> tb >> tc >> td;
		a[i]=ta; b[i]=tb; c[i]=tc; d[i]=td;
	}
	int idx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			ab[i*n+j]=a[i]+b[j];
			cd[i*n+j]=c[i]+d[j];
		}
	}
	sort(ab, ab+n*n);
	sort(cd, cd+n*n, greater<long long>());
	
	int l = 0, r = 0;
	while(l < n*n && r < n*n ){
		if(ab[l] + cd[r] == 0) {
			int orig = l;
			long long sameAB = 0, sameCD = 0;
			while(l < n*n && ab[orig] == ab[l]) {
				sameAB++; l++;
			}
			orig = r;
			while(r < n*n && cd[orig] == cd[r]) {
				sameCD++; r++;
			}
			ans += (sameAB * sameCD);
		}
		else if(ab[l] + cd[r] > 0) r++;
		else if(ab[l] + cd[r] < 0) l++;			
	}
	cout << ans;
	return 0;
}
