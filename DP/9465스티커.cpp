#include <iostream>
#include <math.h>

using namespace std;
// 9465 스티커

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	while(T--){
		
		int N;	cin >> N;
		int arr[2][100001] = { 0, };
		for(int i = 0; i < 2; i++){
			for(int j = 1; j <= N; j++){
				cin >> arr[i][j];
			}
		}
		
		int d[2][100001] = { 0, };
		d[0][1] = arr[0][1];//위에 스티커 붙인 경우 
		d[1][1] = arr[1][1];//아래 
		
		for(int i = 2; i <= N; i++){
			
			int temp = max(d[0][i - 2], d[1][i - 2]);
			// 전에 칸에서 하나도 안붙일 경우
			 
			d[0][i] = max(temp, d[1][i - 1]) + arr[0][i];
			d[1][i] = max(temp, d[0][i - 1]) + arr[1][i];
			
		}
		
		cout << max(d[0][N], d[1][N]) << "\n";
		
	}

	return 0;
	
}
