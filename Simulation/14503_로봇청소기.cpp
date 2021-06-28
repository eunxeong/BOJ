#include <iostream>
#include <cstring>

using namespace std;
// 14503 로봇청소기 

int N, M;
int cnt = 0;
int arr[51][51];
bool visited[51][51];

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
 
void clean(int x, int y, int d){
	
	if (!visited[x][y]){
		visited[x][y] = true;
		cnt++;
	}
	
//	bool flag = false;
	
	for(int i = 1; i <= 4; i++){
		int next = d - i;
		if (next < 0)	next += 4;
		
		int nx = x + dir[next][0];
		int ny = y + dir[next][1];
		
		if (arr[nx][ny] == 0 && !visited[nx][ny]){
			// 벽이 아니고, 아직 청소 안한 곳이면
			clean(nx, ny, next);
			return;
		}
		
	}
	
	int nx = x - dir[d][0];
	int ny = y - dir[d][1];
		
	if (arr[nx][ny] == 0){
		//벽이 아니면
		clean(nx, ny, d);
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	int a, b, d;
	cin >> a >> b >> d;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	memset(visited, false, sizeof(visited));
	clean(a, b, d);
	
	cout << cnt;
	
	return 0;
		
}
