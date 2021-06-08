#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 18352_특정 거리의 도시 찾기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, K, X;	cin >> N >> M >> K >> X;
	
	vector<int> V[300001];
	int INF = 1000000000;
	int d[300001];
	for(int i = 1; i <= N; i++)	d[i] = INF;
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		V[a].push_back(b);
	}
	
	d[X] = 0;
	priority_queue<pair<int, int> > Q;
	Q.push(make_pair(0, X));
	
	while(!Q.empty()){
		
		int cur = Q.top().second;
		int dt = Q.top().first * -1;
		Q.pop();
		 
		if (d[cur] < dt)	continue;
		
		dt++;
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i];
		
			if (d[next] > dt){
				d[next] = dt;
				Q.push(make_pair(-dt, next));
			}
		}
		
	}

	queue<int> ansQ;
	for(int i = 1; i <= N; i++){
		if (d[i] == K)	ansQ.push(i);
	}
	
	if (ansQ.empty())	cout << "-1";
	while(!ansQ.empty()){
		cout << ansQ.front() << "\n";
		ansQ.pop();
	}
	
	return 0;
	
}
