#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int,int>> zeros;
int sudoku[9][9];
int offset[9][2] = {{0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
int row[9], col[9], box[9];
pair<int,int> temp;
int x, y;

bool checkCol(int y, int x) {
	int sum = 0;
	int number = 0;
	if(col[x] == 8) {
		for(int i = 1; i <= 9; i++)
		for(int j = 0; j < 9; j++) {
			if (sudoku[j][x] == i) {
				sum += i;
				break;
			}
		}
		number = 45 - sum;
		sudoku[y][x] = number;
		col[x]++;
		row[y]++;
		box[(y/3)*3 + x/3]++;
		return true;
	}
	return false;
}

bool checkRow(int y, int x) {
	int sum = 0;
	int number = 0;
	if(row[y] == 8) {
		for(int i = 1; i <= 9; i++)
		for(int j = 0; j < 9; j++) {
			if (sudoku[y][j] == i) {
				sum += i;
				break;
			}
		}
		number = 45 - sum;
		sudoku[y][x] = number;
		col[x]++;
		row[y]++;
		box[(y/3)*3 + x/3]++;
		return true;
	}
	return false;
}

bool check3x3(int y, int x) {
	int sum = 0;
	int number = 0;
	int ny = (y/3)*3;
	int nx = (x/3)*3;
	if(box[(y/3)*3 + x/3] == 8) {
		for(int i = 1; i <= 9; i++)
		for(int j = 0; j < 9; j++) {
			if (sudoku[ny+offset[j][0]][nx+offset[j][1]] == i) {
				sum += i;
				break;
			}
		}
		number = 45 - sum;
		sudoku[y][x] = number;
		col[x]++;
		row[y]++;
		box[(y/3)*3 + x/3]++;
		return true;
	}
	return false;
}

int main() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if(!sudoku[i][j]) zeros.push({i,j});
			else {
				col[j]++;
				row[i]++;
				box[(i/3)*3 + (j/3)]++;
			}
		}
	}
	
	while(!zeros.empty()) {
		temp = zeros.front(); zeros.pop();
		y = temp.first; x = temp.second;
		if(checkRow(y,x)) continue;
		if(checkCol(y,x)) continue;
		if(check3x3(y,x)) continue;
		zeros.push(temp);
	}
	
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	} 
	
	return 0;
}
