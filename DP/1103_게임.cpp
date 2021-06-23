#include <iostream>
#include <cstring>

using namespace std;
// 1103 ∞‘¿”

int N, M, Answer;
int arr[51][51];
int d[51][51];
bool visited[51][51];

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int x, int y){
	
	if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 0)	return 0;	
	if (visited[x][y]){
		cout << -1 << "\n";
		exit(0);
	}
	
	if (d[x][y] != -1)	return d[x][y];
	
	visited[x][y] = true;
	d[x][y] = true;
	
	for(int i = 0; i < 4; i++){
		int nx = x + (arr[x][y] * dir[i][0]);
		int ny = y + (arr[x][y] * dir[i][1]);
		d[x][y] = max(d[x][y], dfs(nx, ny) + 1);
	}
	
	visited[x][y] = false;
	return d[x][y];
	
}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < M; j++){
			if (s[j] == 'H')	arr[i][j] = 0;
			else	arr[i][j] = s[j] - '0';
		}
	}
	
	memset(d, -1, sizeof(d));
	memset(visited, false, sizeof(visited));
	
	Answer = dfs(0, 0);
	cout << Answer;
	
	return 0;

}


