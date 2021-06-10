#include <iostream>
#include <math.h>

using namespace std;
// 11404 플로이드

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[101][101];
	int INF = 1000000000;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (i == j)	arr[i][j] = 0;
			else	arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;	
		arr[a][b] = min(arr[a][b], c);
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] + arr[k][j] < arr[i][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (arr[i][j] == INF)	arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
	
}
