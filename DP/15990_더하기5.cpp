#include <iostream>

using namespace std;
// 15990 1, 2, 3 ´õÇÏ±â 5

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	long long d[100001][4] = { 0, };
	
	d[1][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	
	for(int i = 4; i <= 100000; i++){
		
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
		
	}

	while(T--){
		
		int idx;	cin >> idx;
		long long Answer = (d[idx][1] + d[idx][2]) % 1000000009;
		Answer = (Answer + d[idx][3]) % 1000000009;
		
		cout << Answer << "\n";
		
	}
	
	return 0;
	
}
