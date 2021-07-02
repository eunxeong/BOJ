#include <iostream>
#include <cstring>

using namespace std;
// 6550 부분 문자열

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;
	while(1){
		
		cin >> s1 >> s2;
		if (cin.eof())	break;
		
		int idx = 0;
		int start = 0;
		bool flag = true;
		
		while(idx < s2.length()){
			
			int k = s2.find(s1[idx], start);
			if (k == string::npos){
				flag = false;
				break;
			}
			
			start = k + 1;
			idx++;
			
			if (idx == s1.length())	break;
			if (start >= s2.length())	break;
		
		}
		
		if (flag && idx == s1.length())	cout << "Yes\n";
		else	cout << "No\n";
		
	}
	
	return 0;
	
}
