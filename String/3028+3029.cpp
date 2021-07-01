#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 3028 창영마을 3029 경고 11720 숫자의 합 11365 !밀비 급일 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
//	string s;	cin >> s;
//	
//	int cur = 1;
//	
//	for(int i = 0; i < s.length(); i++){
//		int tmp = cur;
//		
//		if (s[i] == 'A'){
//			if (tmp == 1)	cur = 2;
//			if (tmp == 2)	cur = 1;
//		}
//		else if (s[i] == 'B'){
//			if (tmp == 2)	cur = 3;
//			if (tmp == 3)	cur = 2;
//		}
//		else if (s[i] == 'C'){
//			if (tmp == 1)	cur = 3;
//			if (tmp == 3)	cur = 1;
//		}
//	}
//
//	cout << cur;
//	

//	int h, m, s;
//	scanf("%d:%d:%d", &h, &m, &s);
//	int nh, nm, ns;
//	scanf("%d:%d:%d", &nh, &nm, &ns);
//	
//	bool flag;
//	// ntime - time
//	
//	int x, y, z;
//	
//	if (ns < s){
//		flag = true;
//		ns += 60;
//		z = ns - s;
//	}
//	else{
//		flag = false;
//		z = ns - s;
//	}
//	
//	if (flag)	nm--;
//	
//	if (nm < m){
//		flag = true;
//		nm += 60;
//		y = nm - m;
//	}
//	else{
//		flag = false;
//		y = nm - m;
//	}
//	
//	if (flag)	nh--;
//	
//	if (nh < h)	nh += 24;
//	
//	x = nh - h;
//	
//	if (x == 0 && y == 0 && z == 0)	x = 24;
//	if (x >= 24){
//		x = 24;
//		y = 0;
//		z = 0;
//	}
//	
//	printf("%0.2d:%0.2d:%0.2d", x, y, z);
	
//	int ans;	cin >> ans;
//	ans = 0;
//	string s;	cin >> s;
//	for(int i = 0; i < s.length(); i++){
//		ans += s[i] - '0';
//	}
//	cout << ans;
	
	while(1){
		string s;
		getline(cin, s);
		
		if (s == "END")	break;
		
		reverse(s.begin(), s.end());
		cout << s << "\n";
		
	
	}
	return 0;
	
}
