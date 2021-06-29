#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 1120 ¹®ÀÚ¿­

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;	cin >> a >> b;
	
	int ans = 987654321;
	for(int i = 0; i <= b.length() - a.length(); i++){
		int cnt = 0;
		for(int j = i; j < i + a.length(); j++){
			if (a[j - i] != b[j])	cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}
