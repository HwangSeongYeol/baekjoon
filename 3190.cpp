#include <iostream>
#include <queue>

using namespace std;

struct body{
	int x, y;
};
struct moving {
	int t;
	char dir;
};

int N, K, L, ans = 0, hd; //head direction
int board[101][101]; //0=empty, 1=snake, 2=apple  

int main(){
	queue<body> snake;
	queue<moving> moves;
	cin >> N >> K;
	for(int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 2; 
	}
	cin >> L;
	for(int i = 0; i < L; i++) {
		moving temp;
		cin >> temp.t >> temp.dir;
		moves.push(temp);
	}
	
	board[1][1] = 1;
	hd = 1; // right=1 down=2 left=3 up=4
	body head = {1, 1};
	snake.push(head);
	while(1) {
		ans++;
		switch(hd) {
			case 1:
				head.x++;
				break;
			case 2:
				head.y++;
				break;
			case 3:
				head.x--;
				break;
			case 4:
				head.y--;
				break;
		}
		if(head.x == 0 || head.x == N+1 || head.y == 0 || head.y == N+1) { // if the head hits the wall
			break;
		}
		else if (board[head.y][head.x] == 1) { // if the head hits itself.
			break;
		}
		else if (board[head.y][head.x] == 2){ // if the head eats apple.
			board[head.y][head.x] = 1;
		}
		else {
			body tail = snake.front(); snake.pop();
			board[tail.y][tail.x] = 0;
			board[head.y][head.x] = 1;
		}
		if(moves.front().t == ans) { // move the head.
			moving temp = moves.front(); moves.pop();
			switch(temp.dir) { // right=1 down=2 left=3 up=4
				case 'D':
					hd++;
					if(hd>4) hd=1;
					break;
				case 'L':
					hd--;
					if(hd<1) hd=4;
					break;
			}
		}
		snake.push(head);
	}
	cout << ans;
	return 0;
}
