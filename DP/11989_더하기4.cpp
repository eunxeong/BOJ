#include <iostream>

using namespace std;
// 15989 1, 2, 3 더하기 4 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d[10001][4] = { 0, };
	
	d[1][1] = 1;
	d[2][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	
	/* d[i][j] : i를 만들 때 마지막으로 더한 수가 j인 경우
		이렇게 3가지를 나눠서 계산하면 중복되는 경우  *(1, 2) (2, 1)같은*
		를 제거하고 더할 수 있다. */
		 
	for(int i = 4; i <= 10000; i++){
		
		d[i][1] += d[i - 1][1];
		d[i][2] += d[i - 2][1] + d[i - 2][2];
		d[i][3] += d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
		
	}
	
	int T;
	cin >> T;
	while(T--){
		
		int cur;	cin >> cur;
		cout << d[cur][1] + d[cur][2] + d[cur][3] << "\n";	
		
	}
	
	return 0;
	
}
