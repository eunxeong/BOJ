#include <iostream>
#include <cstring>

using namespace std;
// 2240 자두나무

int T, W;
int arr[1001];
int d[3][1001][31];//위치, 초, 이동 횟수 

int func(int tree, int idx, int move){
//지금 있는 나무, 초, 이동 횟수
	// 기저사례
	if (idx > T)	return 0;
	 
	int &res = d[tree][idx][move];
	if (res != -1)	return res;
	
	if (arr[idx] == tree){//현재 있는 위치에서 자두가 떨어지면 
		if (move < W){
			//아직 움직일 수 있다면
			return d[tree][idx][move] = max(1 + func(tree, idx + 1, move), func(3 - tree, idx + 1, move + 1));
			//안움직인(그래서 하나 받음), 움직인 경우 
		}
		else{//움직일 수 없으면 무조건 한 경우 
			return d[tree][idx][move] = 1 + func(tree, idx + 1, move);
		}
	}
	else{//반대쪽에서 떨어진다면 
		if (move < W){
			// 움직일 수 있어서 움직여서 받음 or 안움직여서 못받음 
			return d[tree][idx][move] = max(1 + func(3 - tree, idx + 1, move + 1), func(tree, idx + 1, move));
		}
		else	return d[tree][idx][move] = func(tree, idx + 1, move);
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T >> W;
	
	for(int i = 1; i <= T; i++)	cin >> arr[i];
	
	memset(d, -1, sizeof(d)); 
	cout << func(1, 1, 0);
	
	return 0;	
	 
}
