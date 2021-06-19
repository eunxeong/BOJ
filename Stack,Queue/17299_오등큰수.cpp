#include <iostream>
#include <stack>

using namespace std;
// 17299 오등큰수
 
int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[1000001];
	int cnt[1000001] = { 0, };
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	
	stack<int> S;//그냥 인덱스만 넣을게..?
	int ans[1000001];
	
	for(int i = N - 1; i >= 0; i--){
	
		while (!S.empty() && cnt[arr[i]] >= cnt[S.top()]){
			S.pop();
		}
		
		ans[i] = S.empty() ? -1 : S.top();
		
		S.push(arr[i]);
	}
	
	for(int i = 0; i < N; i++)	cout << ans[i] << " ";
	
	return 0;
	
}
