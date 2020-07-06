#include <iostream>

using namespace std;
int N, MAX=(1<<31), MIN=0x7FFFFFFF;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int temp;
	while(N--) {
		cin >> temp;
		if(temp > MAX) MAX = temp;
		if(temp < MIN) MIN = temp;
	}
	cout << MIN << " " << MAX;
	
	return 0;
}
