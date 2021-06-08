#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 1916 최소 비용 구하기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	vector<pair<int, int> > V[1001];
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		V[a].push_back(make_pair(b, c));
	}
	
	int x, y;	cin >> x >> y;//x -> y
	
	int INF = 1000000000;
	int d[1001];
	for(int i = 1; i <= N; i++)	d[i] = INF;
	
	priority_queue<pair<int, int> > Q;//가중치*-1, 노드
	d[x] = 0;
	Q.push(make_pair(0, x));
	
	while(!Q.empty()){
	
		int k = Q.top().second;
		int w = Q.top().first * -1;
		
		Q.pop();
		
		for(int i = 0; i < V[k].size(); i++){
			int next = V[k][i].first;
			int dt = w + V[k][i].second;
			
			if (d[next] > dt){
				d[next] = dt;
				Q.push(make_pair(-dt, next));
			}
		}
	}
	
	cout << d[y];
	
	return 0;


}
