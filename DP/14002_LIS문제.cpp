#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
// 14002 가장 긴 증가하는 부분 수열 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[1001];
	int d[1001];
	
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	d[0] = 1;
	int ans = 0;
	int idx = 0;//이거때문에 100퍼에서 segfault;; 
	
	for(int i = 1; i < N; i++){
		
		d[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if (arr[i] > arr[j]){
				d[i] = max(d[i], d[j] + 1);
			}
			
		}
		
		if (d[i] > ans){
			ans = d[i];
			idx = i;
		}
		
	}
	
	stack<int> S;
	S.push(arr[idx]);
	idx--;
	ans--;
	
	while(idx >= 0){
		
		if (d[idx] == ans){
			S.push(arr[idx]);
			ans--;
			idx--;
			continue;
		}
		
		idx--;
		
	}
	
	cout << S.size() << "\n";
	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
		
	}
	
	return 0;
}
