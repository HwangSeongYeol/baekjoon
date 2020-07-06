#include <iostream>

using namespace std;

int N, q[16], answer;

void s(int x) {
	for(int i = 0; i < x; i++) if(q[i] == q[x] || q[i]-q[x] == i-x || q[i]-q[x] == x-i) return;
	if(x == N-1) { answer++; return; }
	for(int i = 0; i < N; i++) { q[x+1] = i; s(x+1); }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){ q[0] = i; s(0); }
	cout << answer;
	return 0;
}
