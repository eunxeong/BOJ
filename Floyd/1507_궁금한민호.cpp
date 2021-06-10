#include <iostream>

using namespace std;
// 1507 ±Ã±ÝÇÑ ¹ÎÈ£

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[21][21];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	
	bool ans[21][21] = { false, };
	
	int Answer;
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (i == k || k == j || i == j)	continue;
				
				if (arr[i][k] + arr[k][j] < arr[i][j])	Answer = -1;
				
				if (arr[i][k] + arr[k][j] == arr[i][j]){
					ans[i][j] = true;
				}
			}
		}
	}
	
	if (Answer != -1){
		Answer = 0;
		for(int i = 1; i < N; i++){
			for(int j = i + 1; j <= N; j++){
				if (!ans[i][j])	Answer += arr[i][j];
			}
		}
	}
	
	cout << Answer;
	
	return 0;
	

}
