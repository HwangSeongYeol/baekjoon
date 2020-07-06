#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int as, bs, A[1000], B[1000];
vector<int> sumA, sumB;

int main() {
	cin >> T;
	cin >> as;
	for(int i = 0; i < as; i++) cin >> A[i];
	cin >> bs;
	for(int i = 0; i < bs; i++) cin >> B[i];
	
	for(int i = 0; i < as; i++) {
		int tempSum = A[i];
		sumA.push_back(tempSum);
		for(int j = i+1; j < as; j++) {
			tempSum += A[j];
			sumA.push_back(tempSum);
		}
	}
	
	for(int i = 0; i < bs; i++) {
		int tempSum = B[i];
		sumB.push_back(tempSum);
		for(int j = i+1; j < bs; j++) {
			tempSum += B[j];
			sumB.push_back(tempSum);
		}
	}
	sort(sumB.begin(), sumB.end());
	
	long long ans = 0;
	for(auto a : sumA){
		int ub = upper_bound(sumB.begin(), sumB.end(), T-a) - sumB.begin();
		int lb = lower_bound(sumB.begin(), sumB.end(), T-a) - sumB.begin();
		ans += (ub-lb);
	}
	cout << ans;
	
	return 0;
}
