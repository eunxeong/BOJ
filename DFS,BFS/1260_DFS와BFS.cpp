#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
// 1260 DFS¿Í BFS

int N, M, start;
bool visited[1001];
vector<int> V[1001];

void dfs(int idx){

    if (visited[idx])   return;
    
    visited[idx] = true;
    cout << idx << " ";

    for(int i = 0; i < V[idx].size(); i++){
        if (visited[V[idx][i]]) continue;

        dfs(V[idx][i]);
    }

}

void bfs(){

    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    
    cout << "\n";

    while(!Q.empty()){
        
        int k = Q.size();
        while(k--){
            int cur = Q.front();
            Q.pop();
            cout << cur << " ";

            for(int i = 0; i < V[cur].size(); i++){
                int next = V[cur][i];
                if (visited[next])  continue;

                Q.push(next);
                visited[next] = true;
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> start;
    for(int i = 0; i < M; i++){
        int a, b;   cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) sort(V[i].begin(), V[i].end());

    memset(visited, false, sizeof(visited));
    dfs(start);
    // for(int i = 0; i < V[start].size(); i++){
    //     cout << V[start][i] << endl;
    // }
    memset(visited, false, sizeof(visited));
    bfs();
    return 0;

}