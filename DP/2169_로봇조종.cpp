#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// 2169 ·Îº¿ Á¶Á¾

int N, M;
long long INF = -2e9;

int arr[1001][1001];
long long d[3][1001][1001];//¿Þ, ¿À, ¾Æ·¡·Î 
bool visited[1001][1001];

long long dp(int dir, int x, int y){
	
	if (x == N - 1 && y == M - 1)	return arr[x][y];
	
	if (d[dir][x][y] != INF)	return d[dir][x][y];
	
	visited[x][y] = true;
	long long tmp1 = INF, tmp2 = INF, tmp3 = INF;
	
	if (y - 1 >= 0 && !visited[x][y - 1])	tmp1 = dp(0, x, y - 1);
	if (y + 1 < M && !visited[x][y + 1])	tmp2 = dp(1, x, y + 1);
	if (x + 1 < N && !visited[x + 1][y])	tmp3 = dp(2, x + 1, y);
	
	visited[x][y] = false;
	return d[dir][x][y] = arr[x][y] + max(tmp1, max(tmp2, tmp3));
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
			d[0][i][j] = d[1][i][j] = d[2][i][j] = INF;
		}
	}
	
	memset(visited, false, sizeof(visited));
	
	cout << dp(0, 0, 0) << "\n";
	
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			cout << max(d[0][i][j], max(d[1][i][j], d[2][i][j])) << " ";
//		}
//		cout << endl;
//	}
//	
	return 0;

}
