#include <iostream>

using namespace std;
// 9655 ������

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;  cin >> N;
    if (N % 4 == 0) cout << "CY";
    else    cout << "SK";
    // ���̾���... N=1 �϶����� �������� �����غô��� �㹫�ϰ� Ǯ��
    
    return 0;
}