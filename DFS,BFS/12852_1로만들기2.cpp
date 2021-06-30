#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
// 12852 1로 만들기 2

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	map<int, int> mp;
	
	queue<int> Q;
	mp[N] = -1;
	Q.push(N);
	
	int cnt = 0;
	
	if	(N == 1){
		cout << "0\n1";
	}
	else{
		while(!Q.empty()){
		
			int q_size = Q.size();
			if (mp.find(1) != mp.end())	break;
			cnt++;
			
			while(q_size--){
				int cur = Q.front();
				Q.pop();
				
				int next;
				
				if (cur % 3 == 0){
					next = cur / 3;
					if (mp.find(next) == mp.end()){
						mp[next] = cur;
						Q.push(next);
					}
				}
				if (next == 1)	break;
				
				if (cur % 2 == 0){
					next = cur / 2;
					if (mp.find(next) == mp.end()){
						mp[next] = cur;
						Q.push(next);
					}
				}
				if (next == 1)	break;
				
				next = cur - 1;
				if (mp.find(next) == mp.end()){
					mp[next] = cur;
					Q.push(next);
				}
				
			}
		}
		
		stack<int> ans;
		int idx = 1;
		
		while(idx != -1){
			ans.push(idx);
			idx = mp[idx];
		}
		
		cout << cnt << "\n";
		while(!ans.empty()){
			cout << ans.top() << " ";
			ans.pop();
		}
		
	}
	
	return 0;
}
