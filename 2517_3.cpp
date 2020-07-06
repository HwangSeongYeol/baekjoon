#include <iostream>
#include <set>

using namespace std;

int n, x;
set<int> s;
set<int>::iterator iter;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
		cout << distance(s.find(x), s.end()) << "\n";
	}
}
