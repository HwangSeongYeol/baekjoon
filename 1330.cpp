#include <iostream>

using namespace std;
int A,B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	if(A>B) cout << ">";
	else if(A==B) cout << "==";
	else if(A<B) cout << "<";
	
	return 0;
}
