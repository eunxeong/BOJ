#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 

using namespace std;
// 1707 이분 그래프

int N, E;
vector<int> V[20002];
int cache[20002];// -1이면 안한거고 0, 1로 집합 구분
bool visited[20002];// 큐에 넣었다는 의미로 사용? 

bool Answer = true;

void bfs(int idx){
	
	cache[idx] = 0;
	queue<int> Q;
	Q.push(idx);
	visited[idx] = true;
	
	while(!Q.empty()){
		
		int cur = Q.front();
		Q.pop();
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i];
//			if (visited[next])	continue;
//			
			if (cache[next] == cache[cur]){
				Answer = false;
				return;
			}
			
			cache[next] = !cache[cur];
			if (!visited[next]){
				Q.push(next);
				visited[next] = true;
			}
			
		}
		
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	while(T--){
		
		cin >> N >> E;
		
		for(int i = 1; i <= N; i++)	V[i].clear();
		memset(cache, -1, sizeof(cache));
		memset(visited, false, sizeof(visited));
		
		for(int i = 0; i < E; i++){
			int a, b;	cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		
		Answer = true;
		for(int i = 1; i <= N; i++){
			if (cache[i] == -1)	bfs(i);
		}
		
		if (Answer)	cout << "YES\n";
		else	cout << "NO\n";
		
	}

}
