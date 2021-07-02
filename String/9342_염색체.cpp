#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 9342 염색체

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	
	while(T--){
		
		string s;	cin >> s;
		int k = s[0];
		if (k > 70){
			cout << "Good\n";
			continue;
		}
		
		int idx = 0;
		if (s[0] == 'A')	idx = 1;//A 나왔으니 통과
		
		bool flag = true;
		for(int i = 1; i < s.length(); i++){
			
			if (idx == 0){
				//무조건 A나와야함
				if (s[i] == 'A'){
					idx = 1;
					continue;
				}
				flag = false;
				break;
			}
			
			if (idx == 1){
				// A가 나왔다는거니까
				// 지금 A나와도 되고 아니면 F로 넘어가도됨
				if (s[i] == 'A')	continue;
				else if (s[i] == 'F'){
					idx = 2;
					continue;
				}
				flag = false;
				break;
			}
			
			if (idx == 2){
				if (s[i] == 'F')	continue;
				else if (s[i] == 'C'){
					idx = 3;
					continue;
				}
				flag = false;
				break;
			}
				
			if (idx == 3){
				// 나올거 다 나왔고 C는 계속 나와도 됨
				// 근데 C가 아니라면A, B, C, D, E, F 중에 하나만 나와야함
				
				if (s[i] == 'C')	continue;
				
				if (s.length() - i > 1){
					flag = false;
					break;
				}
				
				int k = s[i];
				if (k > 70){
					flag = false;
					break;
				}
				
			}
		
		}
		
		if (flag)	cout << "Infected!\n";
		else	cout << "Good\n";
		
		
	}


}
