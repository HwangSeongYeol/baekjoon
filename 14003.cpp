#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int N, temp;
int num[MAX];
int list[MAX], pos[MAX];
int main() {
	cin >> N;
	int idx = 1;
	for(int i = 1; i <= N; i++) {
		cin >> num[i];
		if(idx == 1) {
			list[idx] = num[i];
			pos[i] = idx++;
		}
		else if (list[idx-1] < num[i]) {
			list[idx] = num[i];
			pos[i] = idx++;
		}
		else {
			int iter = lower_bound(list+1, list+idx, num[i]) - list;
			list[iter] = num[i];
			pos[i] = iter;
		}
	}
	
	cout << --idx << endl;
	
	vector<int> ans;
	for(int i = N; i >= 1; i--) {
		if(pos[i] == idx) {
			ans.push_back(num[i]);
			idx--;
		}
		if(!idx) break;
	}
	
	while(!ans.empty()) {
		temp = ans.back(); ans.pop_back();
		cout << temp << " ";
	}
	
	return 0;
} 
