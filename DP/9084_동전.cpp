#include <iostream>

using namespace std;
// 9084 µ¿Àü

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int T;	cin >> T;
	
	while(T--){
		
		int N, M;	cin >> N;
		int arr[21];
		for(int i = 1; i <= N; i++)	cin >> arr[i];
		cin >> M;
		
		int d[21][10001] = { 0, };
		
		for(int i = 1; i <= N; i++){
			
			int coin = arr[i];
			for(int j = 1; j <= M; j++){
				
				int p = j / coin;
				
				for(int k = 0; k <= p; k++){
					int q = j - coin * k;	
					if (q == 0){
						d[i][j]++;
						continue;
					}
					
					d[i][j] += d[i - 1][q];
					
				}

			}
			
		}
		
		cout << d[N][M] << "\n";
		
		
	}

	return 0;
	
}
