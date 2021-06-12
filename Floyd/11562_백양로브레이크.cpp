#include <iostream>

using namespace std;
// 11562 백양로 브레이크

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[251][251];
	int INF = 1000000000;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int u, v, b;	cin >> u >> v >> b;
		
		arr[u][v] = 0;
		arr[v][u] = (b == 0) ? 1 : 0;
	
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
	int Q;	cin >> Q;
	while(Q--){
		int x, y;	cin >> x >> y;
		if (x == y)	arr[x][y] = 0; 
		cout << arr[x][y] << "\n";
	}
	
	return 0;
}
