#include <iostream>
#include <stack>

using namespace std;
// 17298 ¿ÀÅ«¼ö

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[1000001];
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	stack<int> S;
	int ans[1000001];

	for(int i = N - 1; i >= 0; i--){
		
		while(!S.empty() && arr[i] >= S.top()){
			S.pop();
		}
		
		ans[i] = S.empty() ? -1 : S.top();
		
		S.push(arr[i]);
		
	}
	
	for(int i = 0; i < N; i++)	cout << ans[i] << " ";
	
	return 0;
	
}
