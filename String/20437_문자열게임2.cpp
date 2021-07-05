#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
// 20437 문자열 게임 2

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> V[26];
	int T;	cin >> T;
	while(T--){
		
		string s;	cin >> s;
		int k;	cin >> k;
		
		for(int i = 0; i < 26; i++){
			V[i].clear();
		}
		
		for(int i = 0; i < s.length(); i++){
			int k = s[i] - 97;
			V[k].push_back(i);
		}
		
		int ans1 = 987654321;
		int ans2 = 0;
		bool flag = false;
		
		for(int i = 0; i < 26; i++){
			if (V[i].size() < k)	continue;	
			
			for(int j = 0; j < V[i].size(); j++){
				int next = j + k - 1;
				if (next >= V[i].size())	continue;
				
				flag = true;
				int tmp = V[i][next] - V[i][j] + 1;
				ans1 = min(ans1, tmp);
				ans2 = max(ans2, tmp);
			}
		}
		
		if (flag)	cout << ans1 << " " << ans2 << "\n";
		else	cout << -1 << "\n";
		
		
	}
	
	
	return 0;
	
}
