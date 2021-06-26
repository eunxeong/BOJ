#include <iostream>
#include <cstring>

using namespace std;
// 1110 더하기 사이클

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int N;	cin >> N;

	int cur = N;
	
	int cnt = 0;
	
	while(1){
	
		cnt++;
		int a = cur / 10;
		int b = cur % 10;
		
		a += b;
		a %= 10;
		
		cur = b * 10 + a;
		
		if (cur == N)	break;
		
	}

	cout << cnt;
	return 0;
	
}
