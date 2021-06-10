#include <iostream>

using namespace std;
// 1956_¿îµ¿

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V, E;	cin >> V >> E;
	int INF = 1000000000;
	int arr[401][401];
	for(int i = 1; i <= V; i++){
		for(int j = 1; j <= V; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < E; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b] = c;
	}
	
	for(int k = 1; k <= V; k++){
		for(int i = 1; i <= V; i++){
			for(int j = 1; j <= V; j++){
				if (arr[i][k] + arr[k][j] < arr[i][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	int Answer = INF;
	for(int i = 1; i < V; i++){
		for(int j = i + 1; j <= V; j++){
			if (arr[i][j] != INF && arr[j][i] != INF){
				Answer = min(Answer, arr[i][j] + arr[j][i]);
			}
		}
	}
	
	if (Answer == INF)	cout << "-1";
	else	cout << Answer;
	
	return 0;

}
