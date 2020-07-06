#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
struct balls {
	int cnt;
	int rx, ry, bx, by;
};

int irx, iry, ibx, iby, ox, oy;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
bool visit[10][10][10][10];
char board[10][10];
char temp;
int ans = -1;
void move(int& x, int& y, int d) {
	while(1) {
		x += dir[d][0], y += dir[d][1];
		if(board[x][y] == '#') {
			x -= dir[d][0], y -= dir[d][1];
			break;
		}
		else if(x == ox && y == oy)
			break;
	}
	return;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> temp;
			if(temp == 'R')
				irx = i, iry = j;
			else if(temp == 'B')
				ibx = i, iby = j;
			else if(temp == 'O')
				ox = i, oy = j;
			else
				board[i][j] = temp;
		}
	}
	
	queue<balls> q;
	q.push({0, irx, iry, ibx, iby});
	visit[irx][iry][ibx][iby] = 1;
	
	while(!q.empty()) {
		balls now = q.front(); q.pop();
		if(now.cnt > 10)
			break;
		if(now.rx == ox && now.ry == oy){
			ans = now.cnt;
			break;
		}
		for(int i = 0; i < 4; i++) {
			int rx = now.rx, ry = now.ry;
			int bx = now.bx, by = now.by;
			move(rx,ry,i);
			move(bx,by,i);
			if(bx == ox && by == oy) continue;
			if(rx == bx && ry == by) {
				switch(i) {
					case 0:	
						now.rx < now.bx ? rx-- : bx--; break;
					case 1:
						now.ry < now.by ? ry-- : by--; break;
					case 2:
						now.rx < now.bx ? bx++ : rx++; break;
					case 3:
						now.ry < now.by ? by++ : ry++; break;
				}
			}
			
			if(!visit[rx][ry][bx][by]) {
				balls next = {now.cnt+1, rx, ry, bx, by};
				q.push(next);
				visit[rx][ry][bx][by] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
