#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 4659 비밀번호 발음하기

// 모음이면 true 
bool arr[26] = { 1, 0, 0, 0, 1,
				0, 0, 0, 1, 0,
				0, 0, 0, 0, 1,
				0, 0, 0, 0, 0,
				1, 0, 0, 0, 0, 0 };

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		string s;	cin >> s;	
		if (s == "end")	break;
		
		bool flag1 = false;
		bool flag2 = true;//같은 문자가 두번 연속 나왔는지 
		int x = 0;//연속해서 나오고 있는 모음 수 
		int y = 0;//연속해서 나오고 있는 자음 수
		 
		for(int i = 0; i < s.length(); i++){
			
			int idx = s[i] - 97;
			if (arr[idx])	flag1 = true;//모음 하나 이상 
			
			if (i != 0){
				if (s[i] == s[i - 1]){
					if (s[i] != 'e' && s[i] != 'o')	flag2 = false;
				}
			}
			
			if (!flag2)	break;//더 할필요 없음
			
			// 이제 자음 모음이 세번 연속으로 나오는지 
			if (arr[idx]){
				// 우선 모음이면
				if (x == 2){
					flag2 = false;
					break;//앞에 두번 연속 나으니까
				}
				x++;
				y = 0;
			}
			else{
				if (y == 2){
					flag2 = false;
					break;
				}
				y++;
				x = 0;
			}
			
			
		}
		
		cout << "<" << s << "> ";
		if (flag1 && flag2){
			cout << "is acceptable.\n";
		}
		else {
			cout << "is not acceptable.\n";
		}
		
	}

	return 0;
	
}
