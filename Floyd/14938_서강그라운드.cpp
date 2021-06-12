#include <iostream>

using namespace std;
// 14938 서강그라운드

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, r;	cin >> N >> M >> r;
	int item[101];
	int arr[101][101];
	int INF = 1000000000;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 1; i <= N; i++)	cin >> item[i];
	
	for(int i = 0; i < r; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] + arr[k][j] < arr[i][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	
	int Answer = 0;
	for(int i = 1; i <= N; i++){
		int tmp = item[i];
		for(int j = 1; j <= N; j++){
			if (i != j && arr[i][j] <= M)	tmp += item[j];
		} 
		Answer = max(tmp, Answer);
	}
	
	cout << Answer;
	
	return 0;
	
}
