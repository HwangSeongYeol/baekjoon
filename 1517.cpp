#include <iostream>
#include <vector>

using namespace std;
int ans = 0;

void merge(int arr[], int l, int m, int r) {
	
	return;
}


void split(int arr[], int l, int r){
	if(l < r) {
		int mid = (l+r)>>1;
		split(arr, l, mid);
		split(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int N, temp;
int arr[500000];
int sorted[500000];
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	split(arr, 0, N-1);
	
	return 0;
}
