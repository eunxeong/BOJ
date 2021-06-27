#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
// 1052 물병

int main(){
 
	int N, K;	cin >> N >> K;
	 
	int ans = 0;
	
	while(1){
		
		int tmpN = N + ans;
		int cnt = 0;
		
		int p = (int)log2(tmpN);
		int q = (int)pow(2, p);
		
		for(int i = p; i >= 0; i--){
			if ((tmpN & q) == q)	cnt++;
			
			q /= 2;
			
			if (q == 0)	break;
		}
		
//		while(p){
//			p = p - (int)pow(2, (int)log2(p));
//			cnt++;
//		}
		
		if (cnt <= K)	break;
		ans++;
		
	}
	
	cout << ans;
	
//	참고한 코드 
//	int tmpN = N;
//	int ans = 0;
//	
//	while(1){
//		
//		int cnt = 0;
//		
//		while(tmpN){
//			
//			if (tmpN % 2 != 0)	cnt++;	
//			
//			tmpN /= 2;
//			
//		}
//		
//		if (cnt <= K)	break;
//		
//		ans++;
//		tmpN = N + ans;
//		
//	}
//	
//	cout << ans;
	return 0;
}
