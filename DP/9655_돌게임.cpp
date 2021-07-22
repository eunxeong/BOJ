#include <iostream>

using namespace std;
// 9655 돌게임

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;  cin >> N;
    if (N % 4 == 0) cout << "CY";
    else    cout << "SK";
    // 어이없다... N=1 일때부터 차근차근 생각해봤더니 허무하게 풀림
    
    return 0;
}