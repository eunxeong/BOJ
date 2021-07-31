#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 14496 �״�, �׸Ӱ� �Ǿ�

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;   cin >> X >> Y;
    int N, M;   cin >> N >> M;
    vector<int> V[1001];

    for(int i = 0; i < M; i++){
        int a, b;   cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int INF = 1000000000;
    int d[1001];
    for(int i = 1; i <= N; i++) d[i] = INF;
    d[X] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, X));

    while(!pq.empty()){

        int cur = pq.top().second;
        int w = pq.top().first * -1;
        pq.pop();

        if (d[cur] < w) continue;

        w++;
        for(int i = 0; i < V[cur].size(); i++){
            int next = V[cur][i];
            if (d[next] <= w)    continue;//�̰� ��ȣ �����ָ� �޸��ʰ�����

            d[next] = w;
            pq.push(make_pair(-w, next));
        }
    }

    int answer = (d[Y] == INF) ? -1 : d[Y];
    cout << answer;

    return 0;
}