#include <iostream>

using namespace std;

int num[1000010], ltor[1000010], rtol[1000010];
int N;
int answer = 0;
int value = 0;

int gcd(int a, int b) {
	if(b == 0) return a;
	gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N;
	
	for(int i = 0; i < N; i++) 
		scanf("%d", &num[i+1]);
	
	ltor[0] = num[0];
	for(int i = 1; i < N; i++) {
		ltor[i] = gcd(ltor[i-1], num[i]);
	}
	rtol[N-1] = num[N-1];
	for(int i = N-2; i >= 0; i--) {
		rtol[i] = gcd(num[i], rtol[i+1]);
	}
	
	int temp = rtol[1];
	if(num[0] < temp || num[1]%temp) {
		if(answer < temp)
			answer = temp;
		value = num[1];
	}
	
	for(int i = 1; i < N; i++) {
		temp = gcd(ltor[i-1], rtol[i+1]);
		if(num[i] < temp || num[i]%temp) { //빠진 수가 temp의 약수라면 
			if(answer < temp){
				answer = temp;
				value = num[i];	
			}
		}
	}
	
	if(num[N-1] < ltor[N-2] || gcd(num[N-1], ltor[N-2]) != temp) {
		if(answer < temp) {
			answer = ltor[N-2];
			value = N-2;	
		}
	}
	
	if(value) 
		cout << answer << " " << value << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
