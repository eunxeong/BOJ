#include <iostream>
#include <math.h>

using namespace std;
// 1389 케빈 베이컨의 6단계 법칙

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[101][101];
	int INF = 1000000000;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][j] > arr[i][k] + arr[k][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	
	int tmpS = INF;
	int ans[101];
	for(int i = 1; i <= N; i++){
		int temp = 0;
		for(int j = 1; j <= N; j++){
			if (i == j)	continue;
			temp += arr[i][j];
		}
		ans[i] = temp;
		tmpS = min(temp, tmpS);
	}
	
	for(int i = 1; i <= N; i++){
		if (ans[i] == tmpS){
			cout << i;
			break;
		}
	}
	
	return 0;
	
}
