#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 6087 레이저 통신

int N, M;
char map[101][101];
bool check[101][101] = { false, };

int start_x, start_y, end_x, end_y;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs(){

    queue<pair<int, int> > Q;
    Q.push(make_pair(start_x, start_y));

    check[start_x][start_y] = true;
    int cnt = -1;

    while(!Q.empty()){

        int k = Q.size();
        cnt++;

        while(k--){

            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++){
                
                int t = 1;
                while(1){

                    int nx = x + dir[i][0]*t;
                    int ny = y + dir[i][1]*t;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                    if (nx == end_x && ny == end_y) return cnt;//도착한거

                    if (map[nx][ny] == '*'){
                        break;//못 뚫고 가니까
                    }

                    if (!check[nx][ny]){//아직 넣었다면 당연히 넣고
                        check[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                    t++;//이칸은 들렸더라도 레이저가 닿는 그 다음칸은 안갔을 수도 있음
                }
            }

        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    int tmp = 0;
    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        for(int j = 0; j < M; j++){
            map[i][j] = s[j];
            if (map[i][j] == 'C'){
                if (tmp == 0){
                    start_x = i;
                    start_y = j;
                    tmp++;
                }
                else{
                    end_x = i;
                    end_y = j;
                }
            }
        }
    }

    int answer = bfs();

    cout << answer;
    return 0;

}