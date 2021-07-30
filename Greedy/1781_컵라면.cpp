#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 1782 컵라면

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;  cin >> N;
    vector<pair<int, int> > V;

    for(int i = 0; i < N; i++){
        int a, b;   cin >> a >> b;
        V.push_back(make_pair(-a, b));//-데드라인, 컵라면수
    } 

    sort(V.begin(), V.end());
    priority_queue<int> pq;

    int idx = 0;
    long long ans = 0;

    for(int i = N; i > 0; i--){
        
        while(idx < N){
            if (-V[idx].first != i) break;
            pq.push(V[idx].second);
            idx++;
        }

        if (pq.empty()) continue;
        ans += pq.top();
        pq.pop();

    }

    cout << ans;
    return 0;
}