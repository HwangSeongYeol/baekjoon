#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K, bits;
int ans = 0;
vector<int> temps;

void DFS(int i, int c) {
	if(c == K) {
		int cnt = 0;
		for(int temp : temps) 
			if((temp|bits) == bits) 
				cnt++;
		ans = max(ans, cnt);
	}
	else {
		for(int j = i; j < 26; j++) {
			if((bits >> j) & 1) continue;
			bits |= (1 << j);
			DFS(j, c + 1);
			bits ^= (1 << j);
		}
	}
	return;
}

int main() {
	cin >> N >> K;
	
	string temp;
	while(N--) {
		cin >> temp;
		int bitTemp = 0;
		for(int i = 0; i < temp.length(); i++) {
			bitTemp |= (1 << temp[i]-'a');
		}
		temps.push_back(bitTemp);
	}
	DFS(0,0);
	
	cout << ans;
	
	return 0;
}
