#include <iostream>

using namespace std;
// 2225 ÇÕºÐÇØ

int main(){
	
	int N, K;	cin >> N >> K;
	
	long long int d[201][201] = { 0, };
	
	for(int i = 1; i <= K; i++)	d[0][i] = 1;
	
	for(int i = 1; i <= N; i++){
		
		d[i][1] = 1;
		for(int j = 2; j <= K; j++){
			
			for(int h = 0; h <= i; h++){
				d[i][j] = (d[i][j] + d[i - h][j - 1]) % 1000000000;
			}
			
		}
		
	}

	cout << d[N][K];
	
	return 0;
}
