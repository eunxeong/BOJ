#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
// 2957 ���� Ž�� Ʈ��

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
            // ���� ū ���ڰ� �ƴ϶��
            height = iterator->second;
        }

        if (iterator != tree.begin()){
            // ���� ���� ���ڰ� �ƴ϶��
            iterator--;//�θ� ����Ű�� �ǰ�?

            height = max(height, iterator->second);
        }

        C += height;
        cout << C << "\n";

        // �� �ڽĳ��ϱ� + 1
        tree[num] = height + 1;

    }

    return 0;
}