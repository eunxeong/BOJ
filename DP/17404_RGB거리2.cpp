#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 17404 RGB 거리 2

int N;
int arr[1001][3];
long long d[1001][3][3];//[0]-[2] R, G, B로 칠했을 경우 

long long dp(int idx, int col, int st){
	
	if (d[idx][col][st] != -1)	return d[idx][col][st];
	
	if (idx == N - 1){//시작 색 생각해서 리턴? 
		if (col == st)	return 987654321;
		else	return arr[idx][col];
//		if (col == 0){
//			if (st == 0)	return d[idx][col][st] = min(arr[idx][1], arr[idx][2]);
//			else if (st == 1)	return d[idx][col][st] = arr[idx][2];
//			else if (st == 2)	return d[idx][col][st] = arr[idx][1];
//		}
//		else if (col == 1){
//			if (st == 1)	return d[idx][col][st] = min(arr[idx][0], arr[idx][2]);
//			else if (st == 2)	return d[idx][col][st] = arr[idx][0];
//			else if (st == 0)	return d[idx][col][st] = arr[idx][2];
//		}
//		else if (col == 2){
//			if (st == 2)	return d[idx][col][st] = min(arr[idx][0], arr[idx][1]);
//			else if (st == 0)	return d[idx][col][st] = arr[idx][1];
//			else if (st == 1)	return d[idx][col][st] = arr[idx][0];
//		}
	}
	
	d[idx][col][st] = arr[idx][col];
	
	if (col == 0){
		return d[idx][col][st] += min(dp(idx + 1, 1, st), dp(idx + 1, 2, st));
	}
	else if (col == 1){
		return d[idx][col][st] += min(dp(idx + 1, 0, st), dp(idx + 1, 2, st));
	}
	else if (col == 2){
		return d[idx][col][st] += min(dp(idx + 1, 0, st), dp(idx + 1, 1, st));
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	// 최솟값 구하기..
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < 3; j++){
//			for(int k = 0; k < 3; k++){
//				d[i][j][k] = -1;
//			}
//		}
//	}
	
	memset(d, -1, sizeof(d));
	
	long long a = dp(0, 0, 0);
	long long b = dp(0, 1, 1);
	long long c = dp(0, 2, 2);
	
	cout << min(min(a, b), c);
	
	return 0; 
}
