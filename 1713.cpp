#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, s[101], temp, t, flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> f(N, {0, 0});
	while(M--) {
		cin >> temp; s[temp]++;
		flag = true;
		for(int i = 0; i < N; i++) {
			if(f[i][0] == 0) {f[i][0] = temp; f[i][1] = ++t; flag = false; break;}
			else if(f[i][0] == temp) { flag = false; break;}
		}
		if(flag) {
			int idx = 0;
			for(int i = 1; i < N; i++) {
				if(s[f[i][0]] == s[f[idx][0]] && f[i][1] < f[idx][1]) idx = i;
				else if(s[f[i][0]] < s[f[idx][0]]) idx = i;
			}
			s[f[idx][0]] = 0; f[idx] = {temp, ++t};
		}
	}
	sort(f.begin(), f.end());
	for(vector<int> temp : f) {cout << temp[0] << " ";} cout << "\n";
	return 0;
}
