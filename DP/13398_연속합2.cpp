#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 13398 ¿¬¼ÓÇÕ 2

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d[100001][2];
//	memset(d, 0, sizeof(d));
	int N;	cin >> N;
	int arr[100001];
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	int ans = -100000000;
	d[0][0] = ans;
	d[0][1] = ans;
	
	for(int i = 1; i <= N; i++){
		
		d[i][0] = max(d[i - 1][0] + arr[i], arr[i]);
		d[i][1] = max(d[i - 1][0], d[i - 1][1] + arr[i]);
		
		ans = max(ans, max(d[i][0], d[i][1]));
		
	}
	
//	for(int i = 0; i < 2; i++){
//		for(int j = 1; j <= N; j++){
//			cout << d[j][i] << " ";
//		}
//		cout << endl;
//	}
	
	cout << ans;
	return 0;

}
