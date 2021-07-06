#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
// 16916 부분 문자열
// 시간초과! KMP 알고리즘으로 다시 풀기 
 
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// 실패함수 구현해보기
	
	string s, b;	cin >> s >> b;
	
	if (s.find(b, 0) != string::npos)	cout << 1;
	else	cout << 0;
	
	return 0;
}
