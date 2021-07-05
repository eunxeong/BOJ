#include <iostream>
#include <set>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
// 7785 회사에 있는 사람 5397 키로거 

bool cmp(string s1, string s2){
	return s1 > s2;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
//	int N;	cin >> N;
//	set<string> ss;
//	
//	for(int i = 0; i < N; i++){
//		string s1, s2;	cin >> s1 >> s2;
//		if (s2[0] == 'e')	ss.insert(s1);	
//		else	ss.erase(s1);
//		
//	}
//
//	vector<string> V;
//	for(auto k : ss)	V.push_back(k);
//	
//	sort(V.begin(), V.end(), cmp);
//	
//	for(auto k : V)	cout << k << "\n";
	
	int T;	cin >> T;
	while(T--){
		string s;	cin >> s;
		deque<char> q;
		
		int cur = 0;//커서 위치
		int k = 0;//사이즈 
		for(int i = 0; i < s.length(); i++){
			
			if (s[i] == '-'){
				if (cur != 0){
					q.erase(q.begin() + cur - 1);
					cur--;
					k--;
				}
			}
			else if (s[i] == '<'){
				cur--;
				if (cur < 0)	cur = 0;
			}
			else if (s[i] == '>'){
				cur++;
				if (cur > k)	cur = k;
			}
			else{
				q.insert(q.begin() + cur, s[i]);
				k++;
				cur++;
				
			}
		}
		
		for(int i = 0; i < q.size(); i++){
			cout << q[i];
		}
		
		cout << "\n";
		
	}
	
	return 0;
}
