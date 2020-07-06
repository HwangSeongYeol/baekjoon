#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int isVisit[500][500];
int board[500][500];
int ans;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void DFS(int depth, int x, int y, int now, int d) {
	if(x<0 || y<0 || x>=N || y>=M)
		return;
	
	now += board[x][y];
	
	if(depth == 3) {
		ans = max(ans, now);
		return;
	}
	
	for(int i = 0; i < 4; i++) {
		if(d == 0 && i == 2) continue;
		if(d == 1 && i == 3) continue;
		if(d == 2 && i == 0) continue;
		if(d == 3 && i == 1) continue;
		DFS(depth+1, x+dir[i][0], y+dir[i][1], now, i);
	}
}

void Tpos(int i, int j) {
	if(i==0 && j==0) return;
	if(i==0 && j==M-1) return;
	if(i==N-1 && j==0) return;
	if(i==N-1 && j==M-1) return;
	
	if(i==0 && !(j==0 || j==M-1)){ //た 
		ans = max(ans, board[i][j] + board[i][j-1] + board[i][j+1] + board[i+1][j]);
	}
	else if(j==0 && !(i==0 || i==N-1)) { //ぬ 
		ans = max(ans, board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j+1]);
	}
	else if(i==N-1 && !(j==0 || j==M-1)){//で 
		ans = max(ans, board[i][j] + board[i][j-1] + board[i][j+1] + board[i-1][j]);
	}
	else if(j==M-1 && !(i==0 || i==N-1)){// っ 
		ans = max(ans, board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j-1]);
	}
	else {
		ans = max(ans, board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j+1]);
		ans = max(ans, board[i][j] + board[i][j-1] + board[i][j+1] + board[i+1][j]);
		ans = max(ans, board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j-1]);
		ans = max(ans, board[i][j] + board[i][j-1] + board[i][j+1] + board[i-1][j]);
	} 
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			DFS(0,i,j, 0, -1);
			Tpos(i, j);
		}
	}	
	cout << ans;
	return 0;
}
