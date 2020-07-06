#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> now1, pre1, tempV;
vector<int> now2, pre2;
int temp, ans_min = 999999, ans_max=0;

int main() {
	cin >> n;
	now1.resize(3);
	pre1.resize(3);
	now2.resize(3);
	pre2.resize(3);
	
	for(int i = 0; i < n; i++) {
		tempV.clear();
		for(int j = 0; j < 3; j++) {
			pre1[j] = now1[j];
			pre2[j] = now2[j];
			cin >> temp;
			tempV.push_back(temp);
		}
		
		now1[0] = max(pre1[0], pre1[1])+tempV[0];
		now1[1] = max(pre1[0], max(pre1[1], pre1[2]))+tempV[1];
		now1[2] = max(pre1[1], pre1[2])+tempV[2];
		now2[0] = min(pre2[0], pre2[1])+tempV[0];
		now2[1] = min(pre2[0], min(pre2[1], pre2[2]))+tempV[1];
		now2[2] = min(pre2[1], pre2[2])+tempV[2];
	}
	for(int t : now1) {
		ans_max = max(ans_max, t);
	}
	for(int t : now2) {
		ans_min = min(ans_min, t);
	}
	
	cout << ans_max << " " << ans_min;
	return 0;
}
