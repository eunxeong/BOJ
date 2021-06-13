#include <iostream>
#include <cstring>

using namespace std;
// 2941 크로아티아 알파벳

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;	cin >> str;
	
	int idx = 0;
	int Answer = 0;
	int len = str.length();
	
	while(idx < len){
	
		if (idx == len - 1){
			Answer++;
			break;
		}
		
		if (str[idx] == 'c'){
			if (str[idx + 1] == '=' || str[idx + 1] == '-'){
				idx = idx + 2;
			}
			else	idx = idx + 1;
		}
		else if (str[idx] == 'd'){
			if (str[idx + 1] == 'z' && str[idx + 2] == '=')	idx = idx + 3;
			else if (str[idx + 1] == '-')	idx = idx + 2;
			else	idx = idx + 1;
		}
		else if (str[idx] == 'l'){
			if (str[idx + 1] == 'j')	idx = idx + 2;
			else	idx = idx + 1;
		}
		else if (str[idx] == 'n'){
			if (str[idx + 1] == 'j')	idx = idx + 2;
			else	idx = idx + 1;
		}
		else if (str[idx] == 's' || str[idx] == 'z'){
			if (str[idx + 1] == '=')	idx = idx + 2;
			else	idx = idx + 1;
		}
		else	idx = idx + 1;
		
		Answer++;
		
	}
		
	cout << Answer;
	return 0;
	

}
