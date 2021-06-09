#include <iostream>

using namespace std;
// 11403 경로찾기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[101][101];
//	int d[101];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int k = 1; k <= N; k++){
		//거쳐가는 정점
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] != 0 && arr[k][j] != 0){
					arr[i][j] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
	
}
