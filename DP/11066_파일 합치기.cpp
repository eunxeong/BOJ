#include <iostream>

using namespace std;
// 11066 파일 합치기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int INF = 100000000;
	int T;	cin >> T;
	while(T--){
		
		int N;	cin >> N;
		int arr[501];
		for(int i = 1; i <= N; i++)	cin >> arr[i];
		
		int sum[501];
		sum[0] = 0;
		sum[1] = arr[1];
		for(int i = 2; i <= N; i++)	sum[i] = sum[i - 1] + arr[i];
		
		int d[501][501] = { 0, };
		
		for(int i = 1; i < N; i++)	d[i][i + 1] = arr[i] + arr[i + 1];
		
		for(int i = 2; i < N; i++){//gap
			
			for(int j = 1; j <= N - i; j++){
				
				int start = j;
				int end = j + i;
				
				int tempS = sum[end] - sum[start - 1];
				d[start][end] = INF;
				for(int mid = start; mid < end; mid++){
					
					d[start][end] = min(d[start][mid] + d[mid + 1][end] + tempS, d[start][end]);
					
				}
				
			}
			
		}
		
		cout << d[1][N] << "\n";
		
	}
		
	return 0;
}
