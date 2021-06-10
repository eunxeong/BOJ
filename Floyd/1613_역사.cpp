#include <iostream>

using namespace std;
// 1613 ¿ª»ç

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int INF = 1000000000;
	int h[401][401] = { 0, };
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		h[a][b] = -1;
		h[b][a] = 1;
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (h[i][k] == 1 && h[k][j] == 1)	h[i][j] = 1;
				else if (h[i][k] == -1 && h[k][j] == -1)	h[i][j] = -1;
			}
		}
	}
	
	int T;	cin >> T;
	while(T--){
		int a, b;	cin >> a >> b;
		cout << h[a][b] << "\n";
			
	}
	
	return 0;
	
}
