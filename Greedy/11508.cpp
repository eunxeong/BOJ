#include <iostream>
#include <algorithm>

using namespace std;
// 11508 2+1 세일
// 멍청 ㅎ 쉽게만 생각하다가 반례 못떠올림
 
bool cmp(int a, int b){
	return a > b;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[100001];
	
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		ans += arr[i];
	}
	
	sort(arr, arr + N, cmp);
	int q = N / 3;
	for(int i = 0; i < q; i++){
		ans -= arr[i * 3 + 2];	
	}
	
	cout << ans;
	
	return 0;
	
}
