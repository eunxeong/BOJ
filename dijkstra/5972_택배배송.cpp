#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 5972 택배 배송

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;   cin >> N >> M;
    vector<pair<int, int> > V[50001];
    for(int i = 0; i < M; i++){
        int a, b, c;    cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }

    int d[50001];
    int INF = 100000000;
    for(int i = 1; i <= N; i++) d[i] = INF;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));

    d[1] = 0;

    bool check[50001] = { false, };

    while(!pq.empty()){

        int cur = pq.top().second;
        int w = pq.top().first*-1;

        pq.pop();

        // if (check[cur]) continue;
        if (w > d[cur]) continue;

        // check[cur] = true;

        for(int i = 0; i < V[cur].size(); i++){
            int next = V[cur][i].first;
            int nw = V[cur][i].second;

            if (w + nw >= d[next])   continue;

            d[next] = w + nw;
            pq.push(make_pair(-d[next], next));

        }
    }

    cout << d[N];

    return 0;
}