#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;
// 5430 AC

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int T;	cin >> T;
	
	while(T--){
		
		string cmd;	cin >> cmd;
		int N;	cin >> N;
			
		string s;	cin >> s;
		deque<int> dq;
		
		string tmp = "";
		
		for(int i = 0; i < s.length(); i++){
			if (s[i] == '[')	continue;
			if (s[i] == ',' || s[i] == ']'){
				if (tmp.length() > 0)	dq.push_back(stoi(tmp));
				tmp = "";
			}
			else	tmp += s[i];
		}
		
		bool flag = true;//순차적으로
		bool ans = true;
		for(int i = 0; i < cmd.length(); i++){
			if (cmd[i] == 'R')	flag = !flag;
			else{
				if (dq.empty()){
					ans = false;
					break;
				}
				else{
					if (flag)	dq.pop_front();
					else	dq.pop_back();
				}
			}
		}
		
		if (!ans)	cout << "error\n";
		else{
			cout << "[";
			if (dq.empty()){
				cout << "]\n";
			}
			else{
				
				if (flag){
					for(int i = 0; i < dq.size() - 1; i++){
						cout << dq[i] << ",";
					}
				
					cout << dq[dq.size() - 1] << "]\n";
				}
				else{
					for(int i = dq.size() - 1; i > 0; i--){
						cout << dq[i] << ",";
					}
					cout << dq[0] << "]\n";
			
				}
			}
			
		}
		
	}
	
	return 0;

}
