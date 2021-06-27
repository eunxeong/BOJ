#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
// 2234 성곽

int N, M, cnt;
int arr[51][51];
int ans1 = 0;//방의 개수 
int ans2 = 0;//가장 넓은 방의 넓이 
	
bool visited[51][51];

int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void bfs(int a, int b){
	
	visited[a][b] = true;
	queue<pair<int, int> > Q;//큐에 넣기 전에 visited하기 
	
	Q.push(make_pair(a, b));	
	while(!Q.empty()){
	
		int x = Q.front().first;
		int y = Q.front().second;
		cnt++;
		Q.pop();
		
		int w = 1;
		
		for(int i = 0; i < 4; i++){
			
			if ((arr[x][y] & w) != w){				
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]){
				
					visited[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
				
			}
			
			w *= 2;
			
		}
	
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> M >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	memset(visited, false, sizeof(visited));
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (!visited[i][j]){
				cnt = 0;
				ans1++;
				bfs(i, j);
				ans2 = max(ans2, cnt);
			}
		}
	}
	
	int ans3 = 0; 
	// 벽 하나씩 없애보기 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int w = 1;
			for(int k = 0; k < 4; k++){
				if ((arr[i][j] & w) == w){
					// 벽이 있으면
					 
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if (x >= 0 && x < N && y >= 0 && y < M){
						//그 벽너머가 정상적인 칸이면 
						arr[i][j] &= ~w;
						cnt = 0;
						memset(visited, false, sizeof(visited));
						bfs(i, j);
						ans3 = max(ans3, cnt);
						arr[i][j] |= w;
					}
				}
				w *= 2;
			}
			
			
		}
	}
	
	
	cout << ans1 << "\n";
	cout << ans2 << "\n";
	cout << ans3 << "\n";
	return 0;
	
}
