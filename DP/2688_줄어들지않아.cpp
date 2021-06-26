#include <iostream>
#include <cstring>

using namespace std;
// 2688 줄어들지 않아

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	int N;
	
	long long d[65][10];
	for(int i = 0; i < 10; i++)	d[1][i] = 1;
	
	for(int i = 2; i < 65; i++){
		for(int j = 0; j < 10; j++){
			d[i][j] = 0;
			for(int k = 0; k <= j; k++){
				d[i][j] += d[i - 1][k];
			}
		}
		
	}
	
	while(T--){
		
		cin >> N;
		long long Answer = 0;
		for(int i = 0; i < 10; i++) Answer += d[N][i];
		
		cout << Answer << "\n";
		
	}
	
	return 0;
}
