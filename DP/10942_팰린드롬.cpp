#include <iostream>

using namespace std;
// 10942 팰린드롬?

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;//<= 2000
	int arr[2001];
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	bool d[2001][2001] = { false, };//[i][j] i부터 j까지 회문인지 
	for(int i = 1; i <= N; i++)	d[i][i] = true;
	
	for(int i = 2; i <= N; i++){//gap
		
		if (i == 2){
			for(int j = 1; j < N; j++){
				if (arr[j] == arr[j + 1])	d[j][j + 1] = true;
			}
			continue;
		}
		
		for(int j = 1; j <= N - i + 1; j++){
			int start = j;
			int end = j + i - 1;
			
			if (arr[start] == arr[end]){
				if (d[start + 1][end - 1])	d[start][end] = true;
			}
			
		}
	
	}
	
	int T;	cin >> T;
	while(T--){
		
		int p, q;	cin >> p >> q;
		cout << d[p][q] << "\n";
		
	}
	
	return 0;
	

}
