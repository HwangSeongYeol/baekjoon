#include <iostream>
#include <algorithm>

using namespace std;
int T;
int segA[4000];
int segB[4000];
int as, bs, ap, bp, A[4000], B[4000];
int sumA[500000];
int sumB[500000];
long long ans;

int init(int tree[], int arr[], int node, int start, int end) {
	if(start == end) 
		return tree[node] = arr[start];
	else {
		int mid = (start+end)>>1;
		return tree[node] = init(tree, arr, node*2, start, mid) + init(tree, arr, node*2+1, mid+1, end);	
	}
}

int query(int tree[], int left, int right, int node, int start, int end) {
	if(right < start || end < left) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start+end)>>1;
	return query(tree, left, right, node*2, start, mid) + query(tree, left, right, node*2+1, mid+1, end);
}

int main() {
	cin >> T;
	cin >> as;
	for(int i = 1; i <= as; i++) cin >> A[i];
	cin >> bs;
	for(int i = 1; i <= bs; i++) cin >> B[i];
	init(segA, A, 1, 1, as);
	init(segB, B, 1, 1, bs);
	
	int cntA = 1;
	for(int i = 1; i <= as; i++) {
		for(int j = i; j <= as; j++) {
			sumA[cntA++] = query(segA, i, j, 1, 1, as);
		}
	}
	
	int cntB = 1;
	for(int i = 1; i <= bs; i++) {
		for(int j = i; j <= bs; j++) {
			sumB[cntB++] = query(segB, i, j, 1, 1, bs);
		}
	}
	sort(sumB+1, sumB+(cntB));
	
	for(int i = 1; i < cntA; i++) {
		int u = upper_bound(sumB+1, sumB+(cntB-1), T-sumA[i]) - (sumB+1);
		int l = lower_bound(sumB+1, sumB+(cntB-1), T-sumA[i]) - (sumB+1);
		ans += (long long)(u-l);
	}
	
	cout << ans;
	return 0;
}
