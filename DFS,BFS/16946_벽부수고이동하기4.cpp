#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
// 16946 벽 부수고 이동하기 4

int N, M;
int MAP[101][101];
int ans[101][101] = { 0, };
int zero[101][101] = { 0, };
int zz[101];
bool visited[101][101];

int zeroN = 0;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };


void bfs(int a, int b){
	
	zeroN++;
	int cnt = 1;
	
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	zero[a][b] = zeroN;
	
	while(!Q.empty()){
		
		int k = Q.size();
		while(k--){
		
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (MAP[nx][ny] == 1 || visited[nx][ny])	continue;
				
				visited[nx][ny] = true;
				zero[nx][ny] = zeroN;
				cnt++;
			}
		
		}
		
	}
	
	zz[zeroN] = cnt;
	
}

void dfs(int x, int y){
	
	if (visited[x][y])	return;
	visited[x][y] = true;
//	cnt++;
	
	for(int i = 0; i < 4; i++){
		
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
//		if (visited[nx][ny] || MAP[nx][ny] != 0)	continue;
		
		dfs(nx, ny);
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < M; j++)	MAP[i][j] = s[j] - '0';
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (MAP[i][j] == 0 && !visited[i][j])	bfs(i, j);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << zz[zero[i][j]];
		}
		cout << "\n";
	}
	
	bool check[500] = {false, };
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (MAP[i][j] == 1){
				int k = 1;
				for(int k = 0; k < 4; k++){
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					memset(check, false, sizeof(check));
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
					if (MAP[nx][ny] == 0)
			
		}
	}
	
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			cout << ans[i][j] % 10;
//		}
//		cout << "\n";
//	}
	
	return 0;
	
}
