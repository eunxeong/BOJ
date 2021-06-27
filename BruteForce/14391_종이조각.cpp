#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 14391 종이 조각 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	int arr[5][5];
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < M; j++)	arr[i][j] = s[j] - '0';
	}

	int ans = 0;
	
	// 모든 경우 다해보기 
	for(int state = 0; state < (1 << N*M); state++){
		
		int tmpS = 0;
		
		for(int i = 0; i < N; i++){
			int rowS = 0;
			
			for(int j = 0; j < M; j++){
				int idx = i * M + j;
				
				if ((state | (1 << idx)) == state){
					
					rowS = rowS * 10 + arr[i][j];
					
				}
				else{
					
					tmpS += rowS;
					rowS = 0;
					
				}
			}
			
			tmpS += rowS;
			
		}
		
		
		for(int j = 0; j < M; j++){
			
			int colS = 0;
			for(int i = 0; i < N; i++){
				
				int idx = j + i * M;
				if ((state | (1 << idx)) != state){
					
					colS = colS * 10 + arr[i][j];
				}
				else{
					
					tmpS += colS;
					colS = 0;
				}
			}
			
			tmpS += colS;
		}
		
		ans = max(ans, tmpS);
		
	}
	
	cout << ans;
	return 0;
	
}
