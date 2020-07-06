#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dice[6] = {0, 0, 0, 0, 0, 0};
int N, M, ix, iy, K;
int board[20][20];
queue<int> spins;
vector<int> ans;

void spin(int dir, int dice[6]) {
	int temp = dice[0];
	switch(dir) {
		case 1: //µ¿ 
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = temp;
			break;
		case 2: //¼­ 
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = temp;
			break;
		case 3: //ºÏ 
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			break;
		case 4: // ³² 
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = temp;
			break;
	}
}

int main() {
	cin >> N >> M >> ix >> iy >> K;
	int dx, dy;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	dx = ix, dy = iy;
	int temp;
	for(int i = 0; i < K; i++) {
		cin >> temp;
		spins.push(temp);
	}
	
	while(!spins.empty()){
		temp = spins.front(); spins.pop();
		switch(temp) {
			case 1:
				dy++;
				if(dy >= M) {
					dy--; 
					continue;
				}
				break;
			case 2:
				dy--;
				if(dy < 0) {
					dy++; 
					continue;
				}
				break;
			case 3:
				dx--;
				if(dx < 0) {
					dx++; 
					continue;
				}
				break;
			case 4:
				dx++;
				if(dx >= N) {
					dx--; 
					continue;
				}
				break;
		}
		spin(temp, dice);
		if(board[dx][dy]){
			dice[5] = board[dx][dy];
			board[dx][dy] = 0;
		}
		else {
			board[dx][dy] = dice[5];
		}
		ans.push_back(dice[0]);
	}	
	for(int answer : ans) {
		cout << answer << endl;
	}
	return 0;
}
