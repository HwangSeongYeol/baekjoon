#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a;
vector<int> v;
int N, K;
int ans;

void DFS(int i, int c) {
	if(c == K-5) {
		int cnt = 0;
		for(int b : v)
			if((a | b) == a) cnt++;
		ans = (cnt > ans) ? cnt : ans;
		return;
	}
	for(int j = i; j < 26; j++) {
		if((a >> j) & 1) 
			continue;
		a |= (1 << j);
		DFS(j, c+1);
		a ^= (1 << j);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	
	string temp;	
	while(N--) { 
		cin >> temp;
		int alp = 0;
		for(int i = 0; i < temp.length(); i++) 
			alp |= (1 << (temp[i] - 'a'));
		v.push_back(alp);
	}
	if(K < 5) {cout << 0; return 0;}
	a |= (1 << ('a'-'a'));
	a |= (1 << ('n'-'a'));
	a |= (1 << ('t'-'a'));
	a |= (1 << ('i'-'a'));
	a |= (1 << ('c'-'a'));
	DFS(0, 0);
	cout << ans;
	return 0;
}
