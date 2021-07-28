#include <iostream>
#include <queue>

using namespace std;
// 1726 로봇

int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;   cin >> N >> M;
    int arr[101][101];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    int start_x, start_y, start_d;
    int end_x, end_y, end_d;
    cin >> start_x >> start_y >> start_d;
    cin >> end_x >> end_y >> end_d;

    if (start_x == end_x && start_y == end_y && start_d == end_d){
        cout << 0;
        return 0;

    }
    start_x--; start_y--;
    end_x--; end_y--;

    bool vt[101][101][5];//마지막껀 방향

    queue<pair<pair<int, int>, int> > Q;
    Q.push(make_pair(make_pair(start_x, start_y), start_d));
    vt[start_x][start_y][start_d] = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 5; k++){
                vt[i][j][k] = false;
            }
        }
    }

    int cnt = 0;
    int answer = -1;
    while(!Q.empty()){

        if (answer != -1)   break;

        int k = Q.size();
        cnt++;
        // cout << endl;
        while(k--){

            // if (answer != -1)   break;
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int d = Q.front().second;
            // cout << x << " " << y << " " << d << endl;
            Q.pop();

            for(int i = 1; i <= 5; i++){
                // 한번에 내릴 수 있는 명령 5개
                int nx = x;
                int ny = y;
                int nd = d;
                if (i == 1){
                    nx = x + dir[d][0];
                    ny = y + dir[d][1];
                }
                else if (i == 2 || i == 3){
                    int tmp_x = x + dir[d][0];
                    int tmp_y = y + dir[d][1];
                    if (tmp_x < 0 || tmp_x >= N || tmp_y < 0 || tmp_y >= M || arr[tmp_x][tmp_y] == 1)   continue;
                    // 만약 한칸뒤가 벽이면 당연히 두칸 뒤로 이동 못함

                    nx = tmp_x + dir[d][0];
                    ny = tmp_y + dir[d][1];
                    if (i == 3){
                        // 3칸뒤로 갈거면 2칸 뒤도 체크해줘야함
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 1) continue;
                        nx = nx + dir[d][0];
                        ny = ny + dir[d][1];
                    }
                }
                else if (i == 4){
                    if (d < 3)  nd = 3;
                    else    nd = 1;
                }
                else if (i == 5){
                    if (d < 3)  nd = 4;
                    else    nd = 2;
                }

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 1 || vt[nx][ny][nd]) continue;

                if (nx == end_x && ny == end_y && nd == end_d){
                    answer = cnt;
                    break;
                }

                Q.push(make_pair(make_pair(nx, ny), nd));
                vt[nx][ny][nd] = true;
                
            }

        }

    }

    cout << answer;

    return 0;

}