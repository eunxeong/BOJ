#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 최단경로 1753

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int, int> > Edge[20001];
	
	int V, E, K;	cin >> V >> E >> K;
	
	for(int i = 0; i < E; i++){
		int a, b, c;	cin >> a >> b >> c;
		Edge[a].push_back(make_pair(b, c));
	}
	
	int d[20001];
	int INF = 1000000000;
	for(int i = 1; i <= V; i++)	d[i] = INF;
	
	priority_queue<pair<int, int> > Q;//가중치, 정점(pq는 내림차순 정렬이므로 음수로 저장할것) 
	bool visited[20001] = { false, };
	d[K] = 0;
	Q.push(make_pair(0, K));
	
	while(!Q.empty()){
	
		int cur = Q.top().second;//정점
		int w = Q.top().first * (-1);
		Q.pop();
		
		visited[cur] = true;
		
		for(int i = 0; i < Edge[cur].size(); i++){
			if (d[Edge[cur][i].first] < Edge[cur][i].second + w)	continue;
			
			d[Edge[cur][i].first] = Edge[cur][i].second + w;
			if (!visited[Edge[cur][i].first]){
				Q.push(make_pair(d[Edge[cur][i].first] * -1, Edge[cur][i].first));
			}
		}
	}
	
	for(int i = 1; i <= V; i++){
		if (visited[i])	cout << d[i];
		else	cout << "INF";
		
		cout << "\n";
	}
	
	return 0;
	
}
