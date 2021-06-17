#include <iostream>
#include <cstring>

using namespace std;
// 1543 문서 검색

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	
	int alen = a.length();
	int blen = b.length();
	
	int Answer = 0;
	int idx = 0;
	
	while(idx < alen){
		
		if (a[idx] == b[0]){
			
			int cur = idx;
			bool ch = true;
			for(int i = 1; i < blen; i++){
				if (a[cur + i] != b[i]){
					ch = false;
					break;
				}
			}
			
			if (ch){
				idx += blen;
				Answer++;
			}
			else	idx++;
			
		}
		else	idx++;
		
		
	}
	
	cout << Answer;
	
	return 0;

}
