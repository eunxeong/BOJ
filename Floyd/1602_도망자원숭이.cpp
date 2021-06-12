#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 1602 µµ¸ÁÀÚ ¿ø¼þÀÌ

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, Q;	cin >> N >> M >> Q;
	vector<pair<int, int> > V;
	
	int p[501];
	for(int i = 1; i <= N; i++){
		int tmp;	cin >> tmp;
		p[i] = tmp;
		V.push_back(make_pair(tmp, i));
	}
	sort(V.begin(), V.end());
	
	int INF = 1000000000;
	int arr[501][501][2];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j][0] = INF;
			arr[j][i][0] = INF;
			
			arr[i][j][1] = max(p[i], p[j]);
			arr[j][i][1] = arr[i][j][1];
		}
	}
			
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b][0] = c;
		arr[b][a][0] = c;
		
		arr[a][b][1] = max(p[a], p[b]);
		arr[b][a][1] = arr[a][b][1];
	}
	
	for(int k = 0; k < V.size(); k++){
		int cur = V[k].second;
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				int dt = arr[i][cur][0] + arr[cur][j][0];
				int t = max(arr[i][cur][1], arr[cur][j][1]);
				
				if (arr[i][j][0] + arr[i][j][1] > dt + t){
					arr[i][j][0] = dt;
					arr[i][j][1] = t;
				}
			
			}
		}
		
	}
	
	while(Q--){
		int x, y;	cin >> x >> y;
		if (arr[x][y][0] == INF)	cout << -1;
		else	cout << arr[x][y][0] + arr[x][y][1];
		
		cout << "\n";
		
	}
	
	return 0;
	
}
