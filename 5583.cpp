#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];
char A[4001], B[4001];

int main() {
	string temp;
	cin >> temp;
	for(int i = 1; i <= temp.length(); i++) {
		A[i] = temp[i-1];
	}
	cin >> temp;
	for(int i = 1; i <= temp.length(); i++) {
		B[i] = temp[i-1];
	}
	
	return 0;
}
