#include <iostream>
#include <algorithm>

using namespace std;
// 2631 줄세우기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[201];
	int d[201];
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	int ans = 0;
	d[0] = 1;
	for(int i = 1; i < N; i++){
		d[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if (arr[i] >= arr[j]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
		ans = max(ans, d[i]);
		
	}
	
	cout << N - ans;
	return 0;
	
}
