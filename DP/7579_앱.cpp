#include <iostream>

using namespace std;
// 7579 앱

struct APP{
	int m;
	int cost;
};

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	APP App[101];
	
	for(int i = 1; i <= N; i++){
		cin >> App[i].m;
	}
	
	int sumC = 0;
	for(int i = 1; i <= N; i++){
		cin >> App[i].cost;
		sumC += App[i].cost;
	}
	
	int d[101][101] = { 0, };

	for(int i = 1; i <= N; i++){//i번 물건까지 사용했을 때 비용 j로 얻을 수 있는 최대 메모리
	
		for(int j = 0; j <= sumC; j++){
			
			if (j < App[i].cost){
				d[i][j] = d[i - 1][j];
				continue;
			}
			
			// 안쓸경우
			// 쓸경우?
			d[i][j] = max(d[i - 1][j], App[i].m + d[i - 1][j - App[i].cost]); 
		
		}
		
	}
	
//	for(int i = 1; i <= N; i++){
//		for(int j = 0; j <= sumC; j++){
//			cout << d[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	for(int i = 0; i <= sumC; i++){
		if (d[N][i] >= M){
			cout << i;
			break;
		}
	}
	
	return 0;
	
}
