#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
// 16916 �κ� ���ڿ�
// �ð��ʰ�! KMP �˰������� �ٽ� Ǯ�� 
 
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// �����Լ� �����غ���
	
	string s, b;	cin >> s >> b;
	
	if (s.find(b, 0) != string::npos)	cout << 1;
	else	cout << 0;
	
	return 0;
}
