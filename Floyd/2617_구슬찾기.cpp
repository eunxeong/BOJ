#include <iostream>

using namespace std;
// 2617 구슬 찾기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[100][100] = { 0, };
	int INF = 1000000000;
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		
		arr[a][b] = -1;//a가 b보다 가볍다 
		arr[b][a] = 1;
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] == 1 && arr[k][j] == 1)	arr[i][j] = 1;
				else if	(arr[i][k] == -1 && arr[k][j] == -1)	arr[i][j] = -1;
			}
		}
	}
	
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	int k = N / 2; 
	int Answer = 0;
	for(int i = 1; i <= N; i++){
		int minus = 0;
		int plus = 0;
		for(int j = 1; j <= N; j++){
			if (i == j)	continue;
			if (arr[i][j] == 1)	plus++;
			else if (arr[i][j] == -1)	minus++;
		}
		
		if (minus > k || plus > k)	Answer++;
		
	}
	
	cout << Answer;
	
	return 0;
	
}
