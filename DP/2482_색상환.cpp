#include <iostream>

using namespace std;
// 2482 ����ȯ

int N, K;
bool start;
long long d[1001][1001][2];//[��][���ݱ���ĥ�Ѽ�][����ĥ�ϴ���]

long long dp(int idx, int cnt, int cur){

    if (d[idx][cnt][cur] != -1){
        // cout << "!" << idx << " " << cnt << cur << ": " << d[idx][cnt][cur] << endl;   
        return d[idx][cnt][cur];
    }
    if (idx == N){
        if (cnt < K)    return 0;

        if (cur == 0)   return 1;

        if (start)  return 0;
        else    return 1;   

    }

    long long tmp1 = dp(idx + 1, cnt, 0) % 1000000003;// �ϴ� ���� ��ĥ�ϴ°� ���� �����ϴϱ�
    long long tmp2 = 0;

    if (cur == 0){
        //���� ��ĥ�ߴٸ� �������� ĥ���� ���� �־
        tmp2 = dp(idx + 1, cnt + 1, 1) % 1000000003;
    }

    // cout << idx << " " << cnt << " " << cur << ":" << tmp1+tmp2 << endl;
    return d[idx][cnt][cur] = (tmp1 + tmp2) % 1000000003;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            d[i][j][0] = -1;
            d[i][j][1] = -1;
        }
    }

    start = false;
    long long answer = dp(1, 0, 0);//ù��°�� ��ĥ��

    // cout << answer << endl;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            d[i][j][0] = -1;
            d[i][j][1] = -1;
        }
    }

    start = true;
    answer = (answer + dp(1, 1, 1)) % 1000000003;

    cout << answer;

    return 0;

}