#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
// 4949 ±ÕÇüÀâÈù ¼¼»ó

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		string s;
		getline(cin, s);	
		
		if (s == ".")	break;
		stack<int> S1, S2;
		bool flag = true;
		
		for(int i = 0; i < s.length(); i++){
			
			if (s[i] == '(')	S1.push(i);
			else if	(s[i] == '[')	S2.push(i);
			else if	(s[i] == ')'){
				if (S1.empty()){
					flag = false;
					break;
				}
				
				if (!S2.empty() && !S1.empty() && S1.top() < S2.top()){
					flag = false;
					break;
				}
				
				S1.pop();
				
			}
			else if	(s[i] == ']'){
				if (S2.empty()){
					flag = false;
					break;
				}
				
				if (!S1.empty() && !S2.empty() && S1.top() > S2.top()){
					flag = false;
					break;
				}
				
				S2.pop();
				
			}
			
			
		}
		
		if (!S1.empty() || !S2.empty())	flag = false;
		
		
		if (flag)	cout << "yes\n";
		else	cout << "no\n";
		
	}
	
	
	return 0;
	 
}
