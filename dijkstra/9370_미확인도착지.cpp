#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;
// 9370 미확인 도착지

int N, M, t, s, g, h, gh;
int INF = 1000000000;
vector<pair<int, int> > V[2001];
vector<int> des;

int path1[2001];//s->
int path2[2001];//h->
int path3[2001];//g->

bool visited[2001];

void Input(){
	
	cin >> N >> M >> t;
	cin >> s >> g >> h;
	
	for(int i = 1; i <= N; i++)	V[i].clear();
	
	for(int i = 0; i < M; i++){
		
		int a, b, c;	cin >> a >> b >> c;
		V[a].push_back(make_pair(b, c));
		V[b].push_back(make_pair(a, c));
		
		if (a == g && b == h)	gh = c;
		if (a == h && b == g)	gh = c;
		
	}
	
	des.clear();
	for(int i = 0; i < t; i++){
		int tmp;	cin >> tmp;
		des.push_back(tmp);
	}
	
}

void Solve(){
	
	Input();
	
	for(int i = 1; i <= N; i++){
		path1[i] = INF;
		path2[i] = INF;
		path3[i] = INF;
	}
	
	memset(visited, false, sizeof(visited));

	//s ->
	priority_queue<pair<int, int> > Q;
	path1[s] = 0;
	Q.push(make_pair(0, s));
	
	while(!Q.empty()){
		
		int cur = Q.top().second;
		int w = Q.top().first * -1;
		Q.pop();
		
		visited[cur] = true;
		if (path1[cur] < w)	continue;
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i].first;
			int ndt = w + V[cur][i].second;
			
			if (path1[next] > ndt){
				path1[next] = ndt;
				Q.push(make_pair(-ndt, next));
			}
		}
		
	}
	
	while(!Q.empty())	Q.pop();
	// h -> 
	path2[h] = 0;
	Q.push(make_pair(0, h));
	memset(visited, false, sizeof(visited));
	while(!Q.empty()){
		
		int cur = Q.top().second;
		int w = Q.top().first * -1;
		Q.pop();
		
		visited[cur] = true;
		if (path2[cur] < w)	continue;
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i].first;
			int ndt = w + V[cur][i].second;
			
			if (path2[next] > ndt){
				path2[next] = ndt;
				Q.push(make_pair(-ndt, next));
			}
		}
		
	}
	
	while(!Q.empty())	Q.pop();
	// g -> 
	path3[g] = 0;
	Q.push(make_pair(0, g));
	memset(visited, false, sizeof(visited));
	while(!Q.empty()){
		
		int cur = Q.top().second;
		int w = Q.top().first * -1;
		Q.pop();
		
		visited[cur] = true;
		if (path3[cur] < w)	continue;
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i].first;
			int ndt = w + V[cur][i].second;
			
			if (path3[next] > ndt){
				path3[next] = ndt;
				Q.push(make_pair(-ndt, next));
			}
		}
		
	}
	
	// s->X, h->X 해서 맞으면 끝이고 아니면 s->X, g->X도 해보기 
	// t개들 전부 돌면서 받는지 확인해주기
	// (s->X) - (s->g->h) = (h->X) 맞는지 
	sort(des.begin(), des.end());
	queue<int> ansQ;
	for(int i = 0; i < des.size(); i++){
		
		int x = des[i];
		int total = path1[x];
		total -= path1[g] + gh;//s->g->h
		if (total == path2[x]){
			ansQ.push(x);
			continue; 
		}
		
		total = path1[x] - path1[h] - gh;//(s->X) - (s->h) - (h->g)
		if (total == path3[x]){
			ansQ.push(x);
		}
		
	}
	
	while(!ansQ.empty()){
		cout << ansQ.front() << " ";
		ansQ.pop();
	}
	
	cout << "\n";
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;	cin >> tc;
	while(tc--){
		Solve();	
	}

	return 0;
	
}
