#include <iostream>

using namespace std;
// 10159 Àú¿ï 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[101][101] = { 0, };
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = -1;
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] == 1 && arr[k][j] == 1)	arr[i][j] = 1;
				else if (arr[i][k] == -1 && arr[k][j] == -1)	arr[i][j] = -1;
			}
		}
	}
	
	int ans[101] = { 0, };
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (i != j && arr[i][j] == 0)	ans[i]++;
		}
		
	}
	
	for(int i = 1; i <= N; i++)	cout << ans[i] << "\n";
	
	return 0;

}
