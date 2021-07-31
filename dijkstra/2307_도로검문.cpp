#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
// 2307 도로검문

int N, M;
int INF = 1000000000;
vector<pair<int, int> > V[1001];
vector<pair<int, int> > qu;
int d[1001];
int path[1001];
int x = -1;
int y = -1;

void dijkstra(int start){

    for(int i = 1; i <= N; i++) d[i] = INF;
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){

        int cur = pq.top().second;
        int w = pq.top().first * -1;
        pq.pop();

        if (d[cur] < w) continue;

        for(int i = 0; i < V[cur].size(); i++){
            int next = V[cur][i].first;
            int nw = V[cur][i].second;
            if (cur == x && next == y)  continue;//폐쇄된 도로
            if (cur == y && next == x)  continue;

            if (d[next] <= w + nw)  continue;

            path[next] = cur;
            d[next] = w + nw;
            pq.push(make_pair(-d[next], next));

        }

    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;


    for(int i = 0; i < M; i++){
        int a, b, c;    cin >> a >> b >> c;

        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }

    int answer = 0;

    dijkstra(1);
    int origin = d[N];

    int num = N;

    while(1){
        if (num == 1)   break;
        qu.push_back(make_pair(path[num], num));
        num = path[num];
    }
    
    if (origin == INF)    answer = -1;

    // 전체 도로를 다 없애주는게 아니라 최단 경로에 사용된 도로들만 없애줬다. 안그러면 시간초과
    for(int i = 0; i < qu.size(); i++){
        if (answer == -1)   break;

        x = qu[i].first;
        y = qu[i].second;
        dijkstra(1);

        if (d[N] == INF)    answer = -1;
        else{
            int tmp = d[N] - origin;
            if (tmp < 0)    tmp = 0;
            answer = max(answer, tmp);
        }

    }

    cout << answer;

    return 0;
}