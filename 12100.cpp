#include <iostream>
#include <algorithm>

using namespace std;


int N;
int board[20][20];
int dir[4][2] = {{0,-1}, {-1,0}, {1,0}, {0,1}}; //аб, ╩С, го, ©Л
int ans = -1;

void move (int d) {
	switch(d) {
		case 0 :
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(!board[i][j]) {
						for(int k = 0; j+k < N; k++){
							if(board[i][j+k]) {
								board[i][j] = board[i][j+k];
								board[i][j+k] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 1 :
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(!board[i][j]) {
						for(int k = 0; i+k < N; k++){
							if(board[i+k][j]) {
								board[i][j] = board[i+k][j];
								board[i+k][j] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 2 :
			for(int i = N-1; i >= 0; i--) {
				for(int j = N-1; j >= 0; j--) {
					if(!board[i][j]) {
						for(int k = 0; i-k >= 0; k++){
							if(board[i-k][j]) {
								board[i][j] = board[i-k][j];
								board[i-k][j] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 3 :
			for(int i = N-1; i >= 0; i--) {
				for(int j = N-1; j >= 0; j--) {
					if(!board[i][j]) {
						for(int k = 0; j-k >= 0; k++){
							if(board[i][j-k]) {
								board[i][j] = board[i][j-k];
								board[i][j-k] = 0;
								break;
							}
						}
					}
				}
			}
			break;
	}
}

void combine(int d) {
	switch(d) { //аб ╩С го ©Л 
		case 0:
			for(int i = 0; i < N; i++) {
				for(int j = 1; j < N; j++) {
					if(board[i][j-1] == board[i][j]){
						board[i][j-1] *= 2;
						board[i][j] = 0;
					}
				}
			}
			break;
		case 1:
			for(int i = 1; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(board[i-1][j] == board[i][j]){
						board[i-1][j] *= 2;
						board[i][j] = 0;
					}
				}
			}
			break;
		case 2:
			for(int i = N-2; i >= 0; i--) {
				for(int j = N-1; j >= 0; j--) {
					if(board[i+1][j] == board[i][j]){
						board[i+1][j] *= 2;
						board[i][j] = 0;
					}
				}
			}
			break;
		case 3:
			for(int i = N-1; i >= 0; i--) {
				for(int j = N-2; j >= 0; j--) {
					if(board[i][j+1] == board[i][j]){
						board[i][j+1] *= 2;
						board[i][j] = 0;
					}
				}
			}
			break;	
	}
}

void DFS(int cnt) {
	if(cnt == 5) {
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++)
				ans = max(ans, board[i][j]);	
		return;
	}
	int temp[20][20];
	
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++)
			temp[i][j] = board[i][j];
	
	for(int i = 0; i < 4; i++) {
		move(i);
		combine(i);
		move(i);
		
		DFS(cnt+1);
		
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++)
				board[i][j] = temp[i][j];
	}
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	DFS(0);
	cout << ans << endl;
	
	return 0;
}
