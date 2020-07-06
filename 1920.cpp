#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> n;
vector<vector<int>> m;
int ans[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> N;
	int temp;
	for(int i = 0; i < N; i++) {
		cin >> temp;
		n.push_back(temp);
	}
	
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> temp;
		m.push_back({temp, i});
	}	
	
	sort(n.begin(), n.end());
	sort(m.begin(), m.end());
	
	int i = 0, j = 0;
	while(j < M) {
		if(m[j][0] == n[i]) {
			ans[m[j][1]] = 1;
			j++;
			continue;
		}
		else if(m[j][0] < n[i]) {
			ans[m[j][1]] = 0;
			j++;
			continue;
		}
		else if(m[j][0] > n[i]) {
			if(i < N-1) i++;
			else j++;
		}
	}
	
	for(int i = 0; i < M; i++)
		cout << ans[i] << "\n";
		
	return 0;
}
