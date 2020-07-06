#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int map[52][52];

int main(){
	int row, col;
	char c;
	cin >> row >> col;
	int springX, springY;
	int startX, startY;
	int endX, endY;
	int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	queue<vector<int>> q;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cin >> c;
			switch(c) {
				case 'D': //����� �� 
					endX = j; endY = i;
					map[i][j] = 2;
					break;
				case 'S': //����ġ�� ��ġ 
					startX = j; startY = i;
					map[i][j] = 3;
					break; 
				case '*': //�칰 
					springX = j; springY = i;
					q.push({springY, springX, 0}); // �칰 ���� �����̰� ���� push 
					map[i][j] = 1;
					break;
				case 'X': //����
					map[i][j] = 2;
					break;
				case '.':
					map[i][j] = 0;
					break;
				default:
					break;
 			}
		}
	}

	q.push({startY, startX, 1}); 
	vector<int> temp;
	while(!q.empty()) {
		temp = q.front(); q.pop();
		if(!temp[2]) { // �칰�� �����̴� �� 
			for(int i = 0; i < 4; i++) {
				if(temp[0] + d[i][0] >= 0 && temp[0] + d[i][0] < row && temp[1] + d[i][1] >= 0 && temp[1] + d[i][1] < col) {
					if(map[temp[0]+d[i][0]][temp[1]+d[i][1]] <= 0 || map[temp[0]+d[i][0]][temp[1]+d[i][1]] == 3) {
						map[temp[0]+d[i][0]][temp[1]+d[i][1]] = 1;
						q.push({temp[0]+d[i][0], temp[1]+d[i][1], 0});
					}
				}
			}
		}
		else {
			for(int i = 0; i < 4; i++) {
				if(temp[0] + d[i][0] >= 0 && temp[0] + d[i][0] < row && temp[1] + d[i][1] >= 0 && temp[1] + d[i][1] < col) {
					if(map[temp[0]+d[i][0]][temp[1]+d[i][1]] == 0) {
						map[temp[0]+d[i][0]][temp[1]+d[i][1]] = -temp[2];
						q.push({temp[0]+d[i][0], temp[1]+d[i][1], temp[2]+1});
					}
					if(temp[0]+d[i][0] == endY && temp[1]+d[i][1] == endX) {
						cout << temp[2]; return 0;
					}
				}
			}
		}
	}
	cout << "KAKTUS";
	
	return 0;
}
