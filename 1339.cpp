#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<int> v;
int a[26] = {0}, ans;
string temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while(N--){
		cin >> temp;
		int offset = 1;
		for(int i = temp.size()-1; i >= 0; i--) {a[temp[i]-'A']+=offset;offset *= 10;} 
	}
	for(int i = 0; i < 26; i++) {if(a[i]) v.push_back(a[i]);}
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < v.size(); i++) {	ans += v[i]*(9-i);}
	cout << ans;
	return 0;
}
