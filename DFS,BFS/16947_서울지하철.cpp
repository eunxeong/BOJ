#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
// 16947 서울 지하철 2호선
// 순환하는지 dfs로 먼저 모두 확인하고 bfs로 순환하는애들이랑 거리 찾기

int N, start;
vector<int> V[3001];
int d[3001];
bool visited[3001];
bool circle = false;//순환선인지 확인

void dfs(int idx, int cot){

    if (visited[idx])   return;
    if (circle) return;

    visited[idx] = true;

    for(int i = 0; i < V[idx].size(); i++){
        int next = V[idx][i];

        if (visited[next]){
            if (cot >= 2 && next == start){
                circle = true;
                return;
            }
            continue;
        }

        dfs(next, cot + 1);
        
    }
}

int bfs(int idx){

    queue<int> Q;
    Q.push(idx);

    memset(visited, false, sizeof(visited));
    // 큐에 넣은건지 확인하기 위함

    visited[idx] = true;

    int dt = 0;

    while(!Q.empty()){

        int k = Q.size();
        dt++;

        while(k--){
            
            int cur = Q.front();
            Q.pop();

            for(int i = 0; i < V[cur].size(); i++){
                int next = V[cur][i];

                if (d[next] == 0){
                    return dt;
                }

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

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;   cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    memset(d, -1, sizeof(d));

    for(int i = 1; i <= N; i++){
        start = i;
        circle = false;
        memset(visited, false, sizeof(visited));
        dfs(i, 0);

        if (circle) d[i] = 0;//순환선에 포함        

    }

    for(int i = 1; i <= N; i++){
        if (d[i] == 0)  continue;

        d[i] = bfs(i);
    }


    for(int i = 1; i <= N; i++){
        cout << i << " : " << d[i] << endl;
    }

    return 0;
}