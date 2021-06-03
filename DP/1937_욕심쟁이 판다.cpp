#include <iostream>
#include <string.h>

using namespace std;
// 1937 øÂΩ…¿Ô¿Ã ∆«¥Ÿ

int N;// 1 <= N <= 500
int MAP[501][501];
int d[501][501] = { 0, };

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int Answer = 0;

void dfs(int x, int y){
	
	d[x][y] = 1;
	
	int tmp = 0;
	
	for(int i = 0; i < 4; i++){
		
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)	continue;
		if (MAP[nx][ny] <= MAP[x][y])	continue;
		
		if (d[nx][ny] == 0)	dfs(nx, ny);
	
		tmp = max(tmp, d[nx][ny]);
	
	}
	
	d[x][y] += tmp;
	Answer = max(Answer, d[x][y]);
	
}

int main(){

	ios_base::sync_with_stdio(0); 	
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> MAP[i][j];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (d[i][j] == 0)	dfs(i, j);
		}
	}

	cout << Answer;
	
	return 0;
	
}
