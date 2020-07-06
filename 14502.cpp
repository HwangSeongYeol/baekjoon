#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct pos{
	int x,y;
};
int N, M; 
int iboard[8][8];
int tempboard[8][8];
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<pos> viruses;
vector<pos> emptySpace;
int ans = -1;

int solve(int depth, int board[8][8]) {
	if(depth > 8) {
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(board[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(board[i][j] == 0) {
				for(int k = 0; k < 4; k++) {
					if(i+d[k][0] != -1 && i+d[k][0] != N && j+d[k][1] != -1 && j+d[k][1] != M) {
						if(board[i+d[k][0]][j+d[k][1]] == 2) {
							board[i][j] = 2;
						}
					}
				}
			}
		}
	}
	return solve(depth+1, board);
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> iboard[i][j];
			if(iboard[i][j] == 0) {
				emptySpace.push_back({i,j});
			}
			else if(iboard[i][j] == 2) {
				viruses.push({i, j});
			}
		}
	}
	vector<int> combinations;
	for(int i = 0; i < emptySpace.size() - 3; i++){
		combinations.push_back(0);
	}
	for(int i = 0; i < 3; i++) {
		combinations.push_back(1);
	}
	int cnt = 1;
	do {
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < M; j++) 
				tempboard[i][j] = iboard[i][j];
		
		for(int i = 0; i < combinations.size(); i++) {
			if(combinations[i]) {
				pos temp = emptySpace.at(i);
				tempboard[temp.x][temp.y] = 1;
			}
		}
		
		ans = max(ans, solve(1, tempboard));
		
	}while(next_permutation(combinations.begin(), combinations.end()));
	
	cout << ans;
	
	return 0;
}
