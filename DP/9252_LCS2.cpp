#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
// 9252 LCS 2

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	
	int d[102][102];
	memset(d, 0, sizeof(d));
	
	for(int i = 1; i <= len2; i++){
		
		for(int j = 1; j <= len1; j++){
			d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			if (s2[i - 1] == s1[j - 1]){
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
			}
			
		}
	
	}

	int x = len2;
	int y = len1;
	stack<char> ans;
	
	while(x > 0 && y > 0){
		
		int tmp = d[x][y];
		if (d[x - 1][y] == tmp){
			x--;
			continue;
		}
		
		if (d[x][y - 1] == tmp){
			y--;
			continue;
		}
		
		ans.push(s2[x - 1]);
		x--;
		y--;
		
	}

	cout << d[len2][len1] << "\n";
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
	
	return 0;
}
