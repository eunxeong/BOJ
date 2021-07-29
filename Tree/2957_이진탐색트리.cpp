#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
// 2957 이진 탐색 트리

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;  cin >> N;
    long long C = 0;
    map<int, int> tree;

    for(int i = 0; i < N; i++){

        int num;    cin >> num;

        if (i == 0){
            tree[num] = 1;
            cout << C << "\n";
            continue;
        }

        auto iterator = tree.upper_bound(num);
        int height = 0;

        if (iterator != tree.end()){
            // 제일 큰 숫자가 아니라면
            height = iterator->second;
        }

        if (iterator != tree.begin()){
            // 제일 작은 숫자가 아니라면
            iterator--;//부모를 가리키는 건가?

            height = max(height, iterator->second);
        }

        C += height;
        cout << C << "\n";

        // 그 자식노드니까 + 1
        tree[num] = height + 1;

    }

    return 0;
}