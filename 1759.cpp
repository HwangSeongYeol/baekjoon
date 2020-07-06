#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int L, C;
string s;
vector<string> v;
bool check(string str) {
	if(str.length()!=L) return false;
	int a=0, b=0;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') a++;
		else b++;
	}
	if(a>=1 && b>=2) return true;
	return false;
}
void DFS(string now, int idx) {
	if(check(now)) cout << now << "\n";	
	for(int i = idx; i < v.size(); i++) {
		if(now.length() < L)
			DFS(now+v[i], i+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;
	while(C--) {cin >> s; v.push_back(s);}
	sort(v.begin(),v.end());
	DFS("",0);
	return 0;
}
