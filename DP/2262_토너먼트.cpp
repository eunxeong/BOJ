#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
// 2262 토너먼트 만들기
// 그리디로 푸는거 모르겠고 DP로 풀기
 
int N;
int arr[257];
int d[257][257];
int winner[257][257];//i~j중에 가장 랭킹 높은애 

int dp(int start, int end){
	
	int &ret = d[start][end];
	
	if (ret != -1)	return ret;
	if (start == end)	return 0;
	
	int mid = winner[start][end];
	
	int left, right;
	if (mid == start)	left = 0;
	else{
		left = dp(start, mid - 1) + (arr[winner[start][mid - 1]] - arr[mid]);
	}
	
	if (mid == end)	right = 0;
	else{
		right = dp(mid + 1, end) + (arr[winner[mid + 1][end]] - arr[mid]);
	}
	
	return ret = left + right;
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	memset(d, -1, sizeof(d));
	
	for(int i = 0; i < N; i++){
		winner[i][i] = i;
		
		for(int j = i + 1; j < N; j++){
			if (arr[winner[i][j - 1]] > arr[j])	winner[i][j] = j;
			else	winner[i][j] = winner[i][j - 1];
		}
	
	}
	
//	cout << winner[1][3] << endl << winner[3][5];
	cout << dp(0, N - 1);
	
	return 0;
	
}
