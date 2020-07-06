#include <iostream>

using namespace std;
int N;
int site[1000000];
int B, C;
long long ans = 0;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> site[i];
	cin >> B >> C;
	for(int i = 0; i < N; i++) {
		site[i] -= B;
		ans++;
		if(site[i] > 0) {
			ans += site[i]/C;
			ans += (site[i]%C) ? 1 : 0;
		}
	}
	cout << ans;
	return 0;
}
