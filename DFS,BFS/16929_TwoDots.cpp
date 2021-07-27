#include <iostream>
#include <string.h>

using namespace std;
// 16929 Two Dots

int N, M;
char arr[51][51];
bool check[51][51];
string answer = "No";

int start_x, start_y;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(int x, int y, int k){

    if (answer == "Yes")    return;
    if (check[x][y])  return;

    check[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (arr[x][y] != arr[nx][ny])   continue;
        if (nx == start_x && ny == start_y && k >= 4){
            answer = "Yes";
            return;
        }
        if (check[nx][ny])  continue;

        dfs(nx, ny, k + 1);

    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        for(int j = 0; j < M; j++)  arr[i][j] = s[j];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (answer == "Yes") break;

            start_x = i;
            start_y = j;
            memset(check, false, sizeof(check));

            dfs(i, j, 1);

        }
    }

    cout << answer;

    return 0;
}