#include <iostream>
#include <cstring>

using namespace std;
// 16916 부분 문자열

string s1, s2;

bool cmp(int idx){
	
	int fin = idx + s2.length();
	if (fin > s1.length())	return false;
	
	for(int i = idx; i < fin; i++){
		if (s1[i] != s2[i - idx])	return false;
	}
	
	return true;
}
 
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s1 >> s2;
	
	bool flag = false;
	int start = 0;
	while(1){
		
		int k = s1.find(s2[0], start);
		
		if (k == string::npos)	break;
		
		if (cmp(k)){
			flag = true;
			break;
		}
		else	start = k + 1;
	
	}
	
	if (flag)	cout << 1;
	else	cout << 0;
	
	return 0;
}
