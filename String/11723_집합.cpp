#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
// 11723 С§Че

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	int S = 0;
	
	while(T--){
		string str;	cin >> str;	
		int n;
		
		switch(str[1]){
			case 'd':
				cin >> n;
				S |= (1 << n);
				break;
			case 'e':
				cin >> n;
				S &= ~(1 << n);
				break;
			case 'h':
				cin >> n;
				if ((S | (1 << n)) == S)	cout << "1\n";
				else	cout << "0\n";
				break;
			case 'o':
				cin >> n;
				S ^= (1 << n);
				break;
			case 'm':
				S = 0;
				break;
			case 'l':
				for(int i = 1; i <= 20; i++)	S |= (1 << i);
				break;
		}
		
	}
	
	return 0;
	
}
