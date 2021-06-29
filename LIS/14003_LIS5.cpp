#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
// 14003 가장 긴 증가하는 부분 수열 5

const int MAXN = 1000001;

struct Code{
	
	int num;//숫자고 
//	int idx;
	int ref;//전에 참고한거, 만약 첫번째꺼면 -1	
	
};

int N;

Code arr[MAXN];
int lis[MAXN][2];//[0]비교 위한 크기, [1]들어간 애의 Code인덱스 

int binarysearch(int left, int right, int target){
	
	int mid;
	
	while(left < right){
		mid = (left + right) / 2;
		
		if (lis[mid][0] == target)	return mid;
		else if (lis[mid][0] < target)	left = mid + 1;
		else	right = mid;
	
	}
	
	return right;
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	cin >> arr[0].num;
	arr[0].ref = -1;
	
	lis[0][0] = arr[0].num;
	lis[0][1] = 0;
	
	int cnt = 1;
	
	for(int i = 1; i < N; i++){
		cin >> arr[i].num;
		
		if (arr[i].num > lis[cnt - 1][0]){
			lis[cnt][0] = arr[i].num;
			lis[cnt][1] = i;
			
			arr[i].ref = lis[cnt - 1][1];//참고한거 = 전에꺼의 인덱스 
			cnt++;
			
		}
		else if	(arr[i].num < lis[0][0]){
			lis[0][0] = arr[i].num;
			lis[0][1] = i;
			
			arr[i].ref = -1;
		
		}
		else {
			
			int k = binarysearch(0, cnt, arr[i].num);
			lis[k][0] = arr[i].num;
			lis[k][1] = i;
			
			arr[i].ref = (k == 0) ? -1 : lis[k - 1][1];
			
		}
		
	}

	cout << cnt << "\n";
	
//	for(int i = 0; i < N; i++){
//		cout << i << " : " << arr[i].num << " " << arr[i].ref << endl;
//		
//		
//	}

//	for(int i = 0; i < cnt; i++){
//		cout << lis[i][0] << " " << lis[i][1] << endl;
//	}
	
	int idx = lis[cnt - 1][1];
//	
//	int cot = 0;
//	cout << endl << lis[cnt - 1][0];
	stack<int> ans;
	while(idx != -1){
		
		ans.push(arr[idx].num);
		idx = arr[idx].ref;
//		cot++;
	}
	
	while(!ans.empty()){
		cout << ans.top() << " ";	
		ans.pop();
	}
	return 0;
}
