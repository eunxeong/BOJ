#include <iostream>
#include <cstring>

using namespace std;
// 16171 나는 친구가 적다 (Small)

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;	cin >> s1 >> s2;
	
	int start = 0;
	
	while(start < s1.length()){
 
		if (s1.find(s2[0], start) == string::npos)	break;
		 
		int idx = s1.find(s2[0], start) + 1;
		
		start = idx;
		int k = 1;//다음에 나와야할거
	
		while(idx < s1.length()){
			
			if (isdigit(s1[idx])){
				idx++;
				continue;
			}
			
			if (s1[idx] == s2[k]){
				idx++;
				k++;
				continue;
			}
			else	break;
			
			if (k == s2.length())	break;
			
		}
		
		if (k == s2.length()){
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	
	return 0;
	
}
