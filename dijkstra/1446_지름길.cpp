#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
// 1446 지름길

class Load{
public:
    int a, b;
    int distance;

    Load(int a, int b, int distance){
        this->a = a;
        this->b = b;
        this->distance = distance;
    }

    bool operator <(Load &load){
        if (this->a == load.a){
            if (this->b == load.b)  return this->distance < load.distance;
            return this->b < load.b;
        }
        return this->a < load.a;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, dt;  cin >> N >> dt;
    vector<Load> V;

    for(int i = 0; i < N; i++){
        int a, b, c;    cin >> a >> b >> c;
        V.push_back(Load(a, b, c));
    }

    sort(V.begin(), V.end());

    int d[10001];
    for(int i = 0; i <= dt; i++)    d[i] = i;

    for(int i = 0; i < N; i++){

        int x = V[i].a;
        int y = V[i].b;
        int k = V[i].distance;

        if (x > dt) break;//더 이상 볼필요 없음

        int cur = d[x] + k;//만약 x에서 y까지 지름길을 통해 간다면
        if (cur > d[y]) continue;//지름길로 갈 필요가 없는 경우
        
        d[y] = cur;
        int tmp = 1;
        for(int j = y + 1; j <= dt; j++){
            d[j] = min(d[j], d[y]+tmp);
            tmp++;
        }

    }

    cout << d[dt];

    return 0;

}