#include <iostream>
#include <cstring>

using namespace std;
// 11062 카드 게임

int N;
int arr[1001];
int d[1001][1001];//start, end
long long Answer;

long long dp(int start, int end, bool turn){
	
	if (d[start][end] != -1)	return d[start][end];
	
	if (start == end){
		if (turn)	return arr[start];
		else	return 0;
	}
	
	if (turn)	return d[start][end] = max(dp(start + 1, end, false) + arr[start], dp(start, end - 1, false) + arr[end]);
	else	return d[start][end] = min(dp(start + 1, end, true), dp(start, end - 1, true));
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		
		memset(d, -1, sizeof(d));
		
		cout << dp(0, N - 1, true) << "\n";
	
	
	}

	return 0;
	
}
