#include <iostream>

using namespace std;
// 2302 극장 좌석

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	int d[41];
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	for(int i = 3; i <= N; i++){
		d[i] = d[i - 1] + d[i - 2];
	}

	if (M == 0)	cout << d[N];
	else{
		int st = 1;
		int Answer = 1;
		
		for(int i = 0; i < M; i++){
			int tmp;	cin >> tmp;	
			
			if (tmp - st != 0)	Answer *= d[tmp - st];
//			cout << Answer << endl;
			st = tmp + 1;
			
		}
	
		if (st < N)	Answer *= d[N - st + 1];
		cout << Answer;
		
	}
	
	
	return 0;
		
}
