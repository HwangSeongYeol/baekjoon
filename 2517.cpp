#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int tree[1048577], x, n;
pii arr[500001];

void update(int pos, int node, int x, int y) {
	if(!(x <= pos && pos <= y)) return;
	tree[node]++;
	if(x != y) {
		int mid = (x + y) >> 1;
		update(pos, node*2, x, mid);
		update(pos, node*2+1, mid+1, y);
	}    
}

int query(int lo, int hi, int node, int x, int y) {
    if (y < lo || hi < x) return 0;
    if (lo <= x && y <= hi) return tree[node];
    int mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

bool cmp(pii a, pii b){
	return a.second < b.second;
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr+1, arr+(n+1));
	
	for(int i = 1; i <= n; i++)
		arr[i].first = i;
		
	sort(arr+1, arr+(n+1), cmp);
	
    for (int i = 1; i <= n; i++) {
        cout << 1 + query(arr[i].first+1, n, 1, 1, n) << "\n";
        update(arr[i].first, 1, 1, n);
    }
    
    return 0;
}
