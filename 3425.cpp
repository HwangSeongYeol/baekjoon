#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define MAX 1000000000

using namespace std;
vector<long long> g;
vector<string> o;
vector<long long> numX;
vector<string> ans; 

void go(vector<long long> g, vector<long long> numX, vector<string> o) {
	int i = 0;
	long long x, y;
	for(string order : o) {
		if(order == "NUM") {
			g.push_back(numX[i++]);
		}
		else if(order == "POP") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			g.pop_back();
		}
		else if(order == "INV") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			g.push_back(-x);
		}
		else if(order == "DUP") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); 
			g.push_back(x);
			
		}
		else if(order == "SWP") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			g.push_back(x);
			g.push_back(y);
		}
		else if(order == "ADD") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			if(x+y > MAX || x+y < -MAX){
				ans.push_back("ERROR");
				return;
			}
			g.push_back(x+y);
		}
		else if(order == "SUB") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			if(y-x > MAX || y-x < -MAX){
				ans.push_back("ERROR");
				return;
			}
			g.push_back(y-x);
		}
		else if(order == "MUL") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			if(x*y > MAX || x*y < -MAX){
				ans.push_back("ERROR");
				return;
			}
			g.push_back(x*y);
		}
		else if(order == "DIV") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			if(x == 0) {
				ans.push_back("ERROR");
				return;
			}
			if(y/x > MAX || y/x < -MAX){
				ans.push_back("ERROR");
				return;
			}
			int neg = 0;
			g.push_back(y/x);
		}
		else if(order == "MOD") {
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			x = g.back(); g.pop_back();
			if(g.empty()){
				ans.push_back("ERROR");
				return;
			}
			y = g.back(); g.pop_back();
			if(x==0) {
				ans.push_back("ERROR");
				return;
			}
			if(y%x > MAX || y%x < -MAX){
				ans.push_back("ERROR");
				return;
			}
				g.push_back(y%x);
		}
	}
	if(g.size() == 1) ans.push_back(to_string(g.front()));
	else ans.push_back("ERROR");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string temp;
	long long tempInt, N;
	
	while(cin >> temp) {
		if(temp == "NUM") {
			o.push_back("NUM");
			cin >> tempInt;
			numX.push_back(tempInt);
		}
		else if(temp == "END") {
			cin >> N;
			while(N--) {
				cin >> tempInt;
				g.push_back(tempInt);
				go(g, numX, o);
				g.clear();
			}
			ans.push_back("");
			o.clear();
			numX.clear();
		}
		else if(temp == "QUIT") {
			break;
		}
		else {
			o.push_back(temp);
		}
	}
	for(int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << "\n";
		
	return 0;
}
