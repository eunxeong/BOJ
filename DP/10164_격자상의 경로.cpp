#include <iostream>

using namespace std;
// 10164 격자상의 경로

/* 문제에선 1번칸이랑 끝칸에는 원 없다그래서 고려 안했는데
   있을경우인 반례 2, 2, 4가 통과 안돼서 틀렸습니다가 떴다
   물론 이거말고도 반례 있었겠지만.. 무튼 그 경우 고려해주니까 통과 */
   
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long d[16][16];
	int N, M, K;	cin >> N >> M >> K;
	d[0][0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (i == 0 && j == 0)	continue;
			else if (i == 0 && j != 0)	d[i][j] = d[i][j - 1];
			else if (i != 0 && j == 0)	d[i][j] = d[i - 1][j];
			else d[i][j] = d[i - 1][j] + d[i][j - 1];
				
		}
	}
	
	if (K == 0)	cout << d[N - 1][M - 1];
	else{
		K--;
		int p = K / M;
		int q = K % M;
		
		cout << d[p][q] * d[N - 1 - p][M - 1 - q];
		
	}
	
	return 0;
	
}
