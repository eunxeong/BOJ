#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
// 18223 민준이와 마산 그리고 건우

int N, E, P;
int INF = 1000000000;
int d[5001];
bool check[5001];
vector<pair<int, int> > V[5001];

void dijkstra(int start){

    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){

        int idx = pq.top().second;
        int dt = pq.top().first*-1;
        pq.pop();

        if (dt > d[idx])    continue;

        for(int i = 0; i < V[idx].size(); i++){
            int next = V[idx][i].first;
            int ndt = V[idx][i].second;

            if (dt + ndt > d[next]) continue;

            d[next] = dt + ndt;
            pq.push(make_pair(-d[next], next));

        }
    }


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E >> P;
    for(int i = 0; i < E; i++){
        int a, b, c;    cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }

    // 건우 생각안하고 바로 마산 가는 경우 계산
    // 여기서 민준이한테 가는 경우도 같이 볼 수 있음
    for(int i = 1; i <= N; i++){
        d[i] = INF;
        check[i] = false;
    }
    dijkstra(1);
    int masan = d[N];
    int tmp = d[P];
    
    for(int i = 1; i <= N; i++){
        d[i] = INF;
        check[i] = false;
    }
    dijkstra(P);
    tmp += d[N];

    if (masan >= tmp)   cout << "SAVE HIM";
    else    cout << "GOOD BYE";

    return 0;
}