#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 6087 레이저 통신

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;   cin >> M >> N;
    char map[101][101];
    vector<pair<int, int> > V;//C 위치
    
    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        for(int j = 0; j < M; j++){
            map[i][j] = s[j];
            if (map[i][j] == 'c'){
                V.push_back(make_pair(i, j));
            }
        }
    }
	
    int d[101][101];
    int INF = 10000000;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)  d[i][j] = INF;
    }

    priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
    d[V[0].first][V[0].second] = 0;
    
//    pq.push(make_pair(make_pair(0, -1), make_pair(V[0].first, V[0].second)));
	pq.push(make_pair(make_pair(0, 0), make_pair(0, 0)));

//    while(!pq.empty()){
//
//        int x = pq.top().second.first;
//        int y = pq.top().second.second;
//        int cur = pq.top().first.second;//이전 방향
//        int w = pq.top().first.first * -1;//지금까지 턴
//
//        pq.pop();
//        if (d[x][y] < w)    continue;
//
//        for(int i = 0; i < 4; i++){
//            int nx = x + dir[i][0];
//            int ny = y + dir[i][1];
//
//            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//            if (map[nx][ny] == '*') continue;
//
//            int nw = w;
//            if (i != cur){
//                if (cur != -1)   nw++;//전과 같은 방향이 아니고 처음 시작도 아니면 한번 꺾었다는거니까 nw++
//            }
//
//            if (d[nx][ny] > nw){
//                pq.push(make_pair(make_pair(-nw, i), make_pair(nx, ny)));
//                d[nx][ny] = nw;
//            }
//        }
//
//    }
//    cout << d[V[1].first][V[1].second];

    return 0;

}
