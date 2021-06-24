#include <iostream>
#include <algorithm>

using namespace std;
// 4796 캠핑
 
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int idx = 1;
	while(1){
		
		int L, P, V;	cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)	break;
		
		int k = V / P;
		int answer = L * k;
		answer += (V % P > L) ? L : V % P;
		
		cout << "Case " << idx << ": " << answer << "\n";
		idx++;
	}
	
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;
// 15904 캠핑

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char ucpc[4] = { 'U', 'C', 'P', 'C' };
	
	string str;
	getline(cin, str);
	
	int len = str.length();
	
	int idx = 0;
	int i = 0;//문자열 뒤질거
	 
	while(i < len){
		
		if (idx == 4)	break;
		
		if (str[i] == ucpc[idx]){
			idx++;
		}
		
		i++;

	}
	
	if (idx == 4)	cout << "I love UCPC";
	else	cout << "I hate UCPC";
	
	return 0;
}
