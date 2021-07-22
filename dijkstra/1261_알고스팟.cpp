#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
// 1261 ¾Ë°í½ºÆÌ

int N, M;
int INF = 100000000;
int arr[102][102];
int d[102][102];  
    
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
   for(int i = 1; i <= N; i++){
        string s;   cin >> s;
        for(int j = 1; j <= M; j++) arr[i][j] = s[j - 1] - '0';
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            d[i][j] = INF;
        }
    }

    d[1][1] = 0;
    priority_queue<pair<int, pair<int, int> > > Q;
    Q.push(make_pair(0, make_pair(1, 1)));
    
    while(!Q.empty()){
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int w = Q.top().first * -1;

        Q.pop();
        if (w > d[x][y])    continue;

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            int nw = w;

            if (nx < 1 || nx > N || ny < 1 || ny > M)   continue;

            if (arr[nx][ny] == 1)    nw++;

            if (d[nx][ny] > nw){
                d[nx][ny] = nw;
                Q.push(make_pair(-nw, make_pair(nx, ny)));
            }
        }
    }

    cout << d[N][M];    
    return 0;
}