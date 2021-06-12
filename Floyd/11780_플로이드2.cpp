#include <iostream>
#include <vector>

using namespace std;
// 11780 플로이드 2

int arr[101][101][2];
int INF = 1000000000;
int N, M;
vector<int> V;

void findRoute(int start, int end){
	
	if (arr[start][end][1] == 0){
		V.push_back(start);
		V.push_back(end);
		return;
	}
	
	findRoute(start, arr[start][end][1]);
	V.pop_back();
	findRoute(arr[start][end][1], end);
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (i == j)	arr[i][j][0] = 0;
			else	arr[i][j][0] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b][0] = min(arr[a][b][0], c);
		arr[a][b][1] = 0;
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k][0] + arr[k][j][0] < arr[i][j][0]){
					arr[i][j][0] = arr[i][k][0] + arr[k][j][0];
					arr[i][j][1] = k;
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (i == j || arr[i][j][0] == INF)	cout << 0;
			else	cout << arr[i][j][0];
			
			cout << " ";
		}
		cout << "\n";
	}
	
	for(int i = 1; i <= N; i++){
		// i == start
		for(int j = 1; j <= N; j++){
			if (i == j || arr[i][j][0] == INF){
				cout << "0\n";
				continue;
			}
			
			V.clear();
			findRoute(i, j);
			
			cout << V.size() << " ";
			for(int k = 0; k < V.size(); k++){
				cout << V[k] << " ";
			}
			cout << "\n";
			
		}
	}
	
	return 0;
	
}
