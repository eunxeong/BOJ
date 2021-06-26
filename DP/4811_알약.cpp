#include <iostream>
#include <cstring>

using namespace std;
// 4811 ¾Ë¾à

int N;
long long d[31][61];

long long dp(int a, int b){
	
	if (d[a][b] != -1)	return d[a][b];
	
	if (a == 0 && b == 1)	return 1;
	
	long long tmp1 = 0;
	long long tmp2 = 0;

	if (a > 0)	tmp1 = dp(a - 1, b + 1);
	if (b > 0)	tmp2 = dp(a, b - 1);
	
	return d[a][b] = tmp1 + tmp2;
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(d, -1, sizeof(d));
	
	while(1){
		cin >> N;
		if (N == 0)	break;
		
		cout << dp(N, 0) << "\n";
		
	}

	return 0;
	
}
