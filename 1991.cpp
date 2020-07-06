#include <iostream>
#include <vector>
using namespace std;
int pos[26], N;
char a, b, c;
vector<vector<int>> tree[26];

void preOrder(int node) {
	cout << (char)(node+'A');
	for(int i = 0; i < tree[node].size(); i++)
		preOrder(tree[node][i][0]);
}
void inOrder(int node) {
	if(!tree[node].empty() && tree[node][0][1])
		inOrder(tree[node][0][0]);
	cout << (char)(node+'A');
	if(!tree[node].empty() && !tree[node][0][1])
		inOrder(tree[node][0][0]);
	else if(tree[node].size()==2)
		inOrder(tree[node][1][0]);
}

void postOrder(int node) {
	if(!tree[node].empty() && tree[node][0][1])
		postOrder(tree[node][0][0]);
	if(!tree[node].empty() && !tree[node][0][1])
		postOrder(tree[node][0][0]);
	else if(tree[node].size()==2)
		postOrder(tree[node][1][0]);	
	cout << (char)(node+'A');
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	while(N--) {
		cin >> a >> b >> c;
		if(!pos[a-'A']) {
			pos[a-'A'] = 1;
		}
		if(b != '.') tree[a-'A'].push_back({b-'A', true});
		if(c != '.') tree[a-'A'].push_back({c-'A', false});
	}
	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	
}
