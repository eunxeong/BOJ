#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
// 17609 회문


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	
	while(T--){
		string str;	cin >> str;	
		int l = 0;
		int r = str.length() - 1;
		
		int ans = 0;
		while(l < r){
			
			if (ans == 2)	break;
			
			if (str[l] == str[r]){
				l++;
				r--;
				continue;
			}
			
			bool tmp = true;
			
			if (str[l + 1] == str[r]){
				int p = l + 2;
				int q = r - 1;
				
				while(p < q){
					if (str[p] == str[q]){
						p++;
						q--;
					}
					else{
						tmp = false;
						break;
					}
				}
				
				if (tmp){
					ans = 1;
					break;
				}
				
			}
			
			tmp = true; 
			//여기까지 왔다는건 여기서 틀리면 답없다는거고 
			if (str[l] == str[r - 1]){
				int p = l + 1;
				int q = r - 2;
				
				while(p < q){
					if (str[p] == str[q]){
						p++;
						q--;
					}
					else{
						tmp = false;
						break;
					}
				
				}
				if (tmp){
					ans = 1;
					break;
				}
			}
		
			ans = 2;
		
		}

		cout << ans << "\n";		
	}
	return 0;
	

}
