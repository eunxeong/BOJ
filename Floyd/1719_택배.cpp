#include <iostream>

using namespace std;
// 1719 ец╧Х

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int N, M;	cin >> N >> M;
	int arr[201][201][2];
	int INF = 1000000000;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j][0] = INF;
//			arr[i][j][1] = ??
		}
	}

	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b][0] = c;
		arr[b][a][0] = c;
		
		arr[a][b][1] = b;
		arr[b][a][1] = a;
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k][0] + arr[k][j][0] < arr[i][j][0]){
					arr[i][j][0] = arr[i][k][0] + arr[k][j][0];
					arr[i][j][1] = arr[i][k][1];
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (i == j)	cout << "- ";
			else	cout << arr[i][j][1] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
