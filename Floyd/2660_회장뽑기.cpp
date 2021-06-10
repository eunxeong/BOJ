#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
// 2660 È¸Àå»Ì±â

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int INF = 1000000000;
	int arr[51][51];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	while(1){
		int a, b;	cin >> a >> b;
		if (a == -1 && b == -1)	break;
		
		arr[a][b] = 1;
		arr[b][a] = 1;	
	}

	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] + arr[k][j] < arr[i][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	int ans[51];
	int num = INF;	
	for(int i = 1; i <= N; i++){
		
		ans[i] = 0;
		
		for(int j = 1; j <= N; j++){
			if (i != j){
				ans[i] = max(ans[i], arr[i][j]);
			}
			
		}

		num = min(num, ans[i]);
	}
	
	
	queue<int> ansQ;
	for(int i = 1; i <= N; i++){
		if (ans[i] == num)	ansQ.push(i);
	}
	
	cout << num << " " << ansQ.size() << "\n";
	while(!ansQ.empty()){
		cout << ansQ.front() << " ";
		ansQ.pop();
	}
	
	return 0;
}
