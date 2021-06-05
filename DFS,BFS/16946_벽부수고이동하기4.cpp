#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
// 16946 벽 부수고 이동하기 4

int N, M;
int MAP[1001][1001];
int ans[1001][1001];
int zero[1001][1001] = { 0, };
int zeroN = 0;
int area[500001];

bool visited[1001][1001] = { false, };
bool check[500001];

int dir[4][2] = { { 0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs(int a, int b){
	
	visited[a][b] = true;
	zeroN++;//0칸 번호
	zero[a][b] = zeroN;
	 
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	
	int cnt = 1;//0 개수 카운트
	
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
				Q.push(make_pair(nx, ny));
			}
		}
	
	}
		
	area[zeroN] = cnt;
	
}

void countAns(int x, int y){
	
	memset(check, false, sizeof(check));
	int cnt = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		if (MAP[nx][ny])	continue;
		
		if (check[zero[nx][ny]])	continue;
		cnt += area[zero[nx][ny]];
		check[zero[nx][ny]] = true;
		
	}
	
	ans[x][y] = cnt % 10;
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
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
			if (MAP[i][j] == 1){
				countAns(i, j);
			}
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << ans[i][j];
		}
		cout << "\n";
	}
	
	return 0;
	
}
