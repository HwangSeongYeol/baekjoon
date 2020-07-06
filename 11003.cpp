#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
int N, L, temp;

struct cmp {
	bool operator()(pii a, pii b) {
		return a.first > b.first;
	}
};

priority_queue<pii, vector<pii>, cmp> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for(int i = 0; i < N; i++) {
		cin >> temp;
		pq.push({temp, i});
		while(!pq.empty() && pq.top().second <= i-L) 
			pq.pop();
		cout << pq.top().first << " ";
	}
	return 0;
}
