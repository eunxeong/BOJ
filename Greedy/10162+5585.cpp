#include <iostream>
#include <algorithm>

using namespace std;
// 5585 거스름돈

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[7] = { 500, 100, 50, 10, 5, 1 };
	
	int money;	cin >> money;
	money = 1000 - money;
	
	int cnt = 0;
	int idx = 0;
	
	while(money > 0 && idx < 6){
		
		int tmp = money / arr[idx];
		if (tmp > 0){
			cnt += tmp;
			money = money % arr[idx];
		}
		
		idx++;
		
	}

	cout << cnt;
	
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;
// 10162 전자레인지

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[3] = { 300, 60, 10 };
	int ans[3] = { 0, };
	
	int total;	cin >> total;
	
//	int cnt ?= 0;
	int idx = 0;
	
	while(total > 0 && idx < 3){
		
		int tmp = total / arr[idx];
		if (tmp > 0){
			ans[idx] = tmp;
			total = total % arr[idx];
		}
		
		idx++;
		
	}

	if (total != 0)	cout << -1;
	else{
		cout << ans[0] << " " << ans[1] << " " << ans[2];	
		
	}
	
	return 0;
}
