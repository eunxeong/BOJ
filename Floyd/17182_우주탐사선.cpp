#include <iostream>

using namespace std;
// 17182 우주 탐사선

#define INF 987654321

int N, start;
int arr[11][11];
bool visited[11] = { false, };
int Answer = INF;
	
void dfs(int idx, int dt, int cnt){
	//현재 위치, 지금까지 거리, 지금까지 지나온 행성 수 
	if (dt > Answer)	return;
	if (cnt == N){
		Answer = min(Answer, dt);
		return;
	}
	
	for(int i = 1; i <= N; i++){
		if (visited[i])	continue;
		
		visited[i] = true;
		dfs(i, dt + arr[idx][i], cnt + 1);
		visited[i] = false;
		
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> start;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
	visited[start + 1] = true;
	dfs(start + 1, 0, 1);
	
	cout << Answer;
	return 0;
	
}
