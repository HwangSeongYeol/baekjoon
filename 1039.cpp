#include <iostream>
#include <string>
#include <queue>

using namespace std;
int v[1000001];
string N;
int k, K, ans;
queue<string> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	if(N.length() == 1 || (N.length() == 2 && N[1] == '0')) {cout << -1; return 0;}
	q.push(N);
	while(!q.empty() && k++<K) {
		int qs = q.size();
		for(int s = 0; s < qs; s++) {
			string now = q.front(); q.pop();
			for(int i = 0; i < now.length(); i++) {
				for(int j = i+1; j < now.length(); j++) {
					if(i==0 && now[j] == '0') continue;
					swap(now[i], now[j]);
					if(v[stoi(now)] < k) {
						v[stoi(now)] = k; q.push(now);
						if(k == K) ans = max(ans, stoi(now));
					}
					swap(now[i], now[j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
