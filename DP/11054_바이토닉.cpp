#include <iostream>
#include <algorithm>

using namespace std;
// 11054 가장 긴 바이토닉 부분 수열

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[1001];
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int d1[1001];
	int d2[1001];
	
	d1[0] = 1;
	for(int i = 1; i < N; i++){
		d1[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if (arr[i] > arr[j]){
				d1[i] = max(d1[i], d1[j] + 1);
			}
		}
	}
	
	int ans = 1;
	d2[N - 1] = 1;
	for(int i = N - 2; i >= 0; i--){
		d2[i] = 1;
		for(int j = i + 1; j < N; j++){
			if (arr[i] > arr[j]){
				d2[i] = max(d2[i], d2[j] + 1);
			}
		}
		ans = max(ans, d1[i] + d2[i] - 1);
	}
	
	cout << ans;
	return 0;
}
