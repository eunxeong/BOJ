#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
// 17413 단어 뒤집기 2

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	getline(cin, str);
	
	stack<char> S;
	
	int idx = 0;
	while(idx < str.length()){
		
		if (str[idx] == ' '){
			while(!S.empty()){
				cout << S.top();
				S.pop();	
			}
			cout << str[idx];
			idx++;
			continue;
		}
		
		if (str[idx] == '<'){
			while(!S.empty()){
				cout << S.top();
				S.pop();
			}
			int k = str.find('>', idx);
			for(int i = idx; i <= k; i++){
				cout << str[i];
			}
			idx = k + 1;
			continue;
		}
		
		S.push(str[idx]);
		idx++; 
	}

	while(!S.empty()){
		cout << S.top();
		S.pop();
	}

	return 0;
	
}
