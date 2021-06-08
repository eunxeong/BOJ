#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 2211 네트워크 복구

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	vector<pair<int, int> > V[1001];
	int d[1001];
	int INF = 1000000000;
	int p[1001];
	
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		V[a].push_back(make_pair(b, c));
		V[b].push_back(make_pair(a, c));
	}
	
	d[1] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, 1));
	
	bool visited[1001] = { false, };
	
	for(int i = 2; i <= N; i++)	d[i] = INF;
	
	while(!pq.empty()){
		
		int cur = pq.top().second;
		int dt = pq.top().first * -1;
		pq.pop();
		
//		visited[cur] = true;
		if (d[cur] < dt)	continue;
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i].first;
			int ndt = dt + V[cur][i].second;
			
			if (d[next] > ndt){
				d[next] = ndt;
				p[next] = cur;
				pq.push(make_pair(-ndt, next));
			}
		}
		
	}
	
	cout << N - 1 << "\n";
	for(int i = 2; i <= N; i++){
		cout << i << " " << p[i] << "\n";
	}
	
	return 0;

}
