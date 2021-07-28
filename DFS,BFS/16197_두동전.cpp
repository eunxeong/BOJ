#include <iostream>
#include <queue>

using namespace std;
// 16197 �� ����

struct Coin{
    int x, y;
};

int N, M;
char arr[21][21];
Coin c1, c2;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs(){

    queue<pair<Coin, Coin> > Q;
    Q.push(make_pair(c1, c2));

    int cnt = 0;
    bool pass1, pass2;

    while(!Q.empty()){

        int k = Q.size();
        cnt++;

        // cout << cnt << endl;
        if (cnt > 10)   return -1;

        while(k--){
            
            Coin a1 = Q.front().first;
            Coin a2 = Q.front().second;
            Q.pop();

            Coin b1, b2;

            for(int i = 0; i < 4; i++){

                pass1 = pass2 = false;
                b1.x = a1.x + dir[i][0];
                b1.y = a1.y + dir[i][1];
                // cout << b1.x << " " << b1.y;
                b2.x = a2.x + dir[i][0];
                b2.y = a2.y + dir[i][1];
                // cout << " " << b2.x << " " << b2.y << endl;

                if (b1.x < 0 || b1.x >= N || b1.y < 0 || b1.y >= M){
                    pass1 = true;//ù��° ���� ������
                }
                else{
                    if (arr[b1.x][b1.y] == '#'){
                        b1 = a1;//�ȿ����̰� �״��
                    }
                }
            
                if (b2.x < 0 || b2.x >= N || b2.y < 0 || b2.y >= M){
                    pass2 = true;
                }
                else{
                    if (arr[b2.x][b2.y] == '#'){
                        b2 = a2;
                    }
                }

                if (pass1 && pass2) continue;//�Ѵ� �������Ŵϱ� �н���
                if (pass1 && !pass2)    return cnt;
                if (!pass1 && pass2)    return cnt;//�Ѱ��� ������ ���

                if (a1.x == b1.x && a1.y == b1.y && a2.x == b2.x && a2.y == b2.y)   continue;
                // ���� �ƴϰ� �Ѵ� �׳� ��ĭ�� �̵��ѰŸ� ť�� �ֱ�
                Q.push(make_pair(b1, b2));

            }

            
        }
    }

    return -1;//10�� �Ѿ��ų� ť���� ����?

}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int tmp = 0;
    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        for(int j = 0; j < M; j++){
            arr[i][j] = s[j];
            if (arr[i][j] == 'o'){
                if (tmp == 0){
                    c1.x = i;
                    c1.y = j;
                    tmp = 1;
                }
                else{
                    c2.x = i;
                    c2.y = j;
                }
            }
        }
    }

    int answer = bfs();

    cout << answer;
    return 0;

}