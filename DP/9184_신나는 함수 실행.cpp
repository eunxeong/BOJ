#include <iostream>

using namespace std;
// 9184 신나는 함수 실행

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d[21][21][21] = { 0, };
	
	for(int i = 0; i < 21; i++){
		for(int j = 0; j < 21; j++){
			for(int k = 0; k < 21; k++){
				if (i == 0 || j == 0 || k == 0){
					d[i][j][k] = 1;
				}
				else if (i < j && j < k){
					d[i][j][k] = d[i][j][k - 1] + d[i][j - 1][k - 1] - d[i][j - 1][k];
				}
				else {
					d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1] - d[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	
	while(1){
		
		int a, b, c;	cin >> a >> b >> c;
	
		if (a == -1 && b == -1 && c == -1)	break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		
		if (a <= 0 || b <= 0 || c <= 0){
//			a = 0; b = 0; c = 0;
			a = b = c = 0;
		}
		else if (a > 20 || b > 20 || c > 20){
//			a = 20; b = 20; c = 20;
			a = b = c = 20;
		}
		
		cout << d[a][b][c] << "\n";
	}
			
	return 0;
}
