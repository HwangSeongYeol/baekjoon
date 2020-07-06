#include <iostream>
#include <string>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	string aster= "*";
	for(int i = 0; i < N; i++) {
		cout << aster << "\n";
		aster = aster + "*";
	}
	return 0;
}
