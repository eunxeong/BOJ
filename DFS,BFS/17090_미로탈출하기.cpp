#include <iostream>
#include <string.h>

using namespace std;
// 17090 πÃ∑Œ ≈ª√‚«œ±‚

int N, M;
char arr[501][501];
int d[501][501];//-1 πÊπÆx, 0 ≈ª√‚x, 1 ≈ª√‚o

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };//U R D L
bool check[501][501] = { false, };

int dfs(int x, int y){

    if (d[x][y] != -1)  return d[x][y];

    if (check[x][y])    return d[x][y] = 0;
    check[x][y] = true;

    int k;
    if (arr[x][y] == 'U')   k = 0;
    else if (arr[x][y] == 'R')  k = 1;
    else if (arr[x][y] == 'D')  k = 2;
    else if (arr[x][y] == 'L')  k = 3;

    int nx = x + dir[k][0];
    int ny = y + dir[k][1];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return d[x][y] = 1;

    return d[x][y] = dfs(nx, ny);
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        for(int j = 0; j < M; j++)  arr[i][j] = s[j];
    }

    memset(d, -1, sizeof(d));

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (d[i][j] == -1)  dfs(i, j);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (d[i][j] == 1)   answer++;
        }
    }

    cout << answer;
    return 0;
}