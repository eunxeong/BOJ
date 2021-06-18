#include <iostream>
#include <algorithm>

using namespace std;
// 1092 배

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	int crane[51];
	int box[10001];
	cin >> N;
	for(int i = 0; i < N; i++)	cin >> crane[i];
	cin >> M;
	for(int i = 0; i < M; i++)	cin >> box[i];
	
	sort(crane, crane + N);
	sort(box, box + M);
	
	int arr[51] = { 0, };
	
	int idx = 0;
	int k = 0;
	// idx번이 들 수 있는 박스 개수
	
	while(idx < N && k < M){
		
		int p = 0;
		
		while(k < M){
			if (crane[idx] >= box[k]){
				p++;
				k++;
			}
			else	break;
		}
		
		arr[idx] = p; 
		idx++;
		
	}
	
	int Answer = 0; 
	for(int i = N - 1; i >= 0; i--){
		if (arr[i] == 0)	continue;	
		
		int cur = N - i;//지금 남는 크레인 수 
		// c개가 몇번 들어야 arr[i]를 들 수 있는지? 
		
		int p = arr[i] / cur;
		if (arr[i] % cur != 0)	p++;
		// p번 더 들어야한다
		
		Answer += p; 
		
		cur = cur * p - arr[i];
		arr[i] = 0;
		
		for(int j = i - 1; j >= 0; j--){
			cur += p;
			
			if (arr[j] == 0){
				continue;
			}
			
			if (arr[j] >= cur){
				arr[j] -= cur;
				cur = 0;
			}
			else{
				cur -= arr[j];
				arr[j] = 0;
			}
		}
		
	}
	
	if (k < M)	cout << "-1";
	else	cout << Answer;

	return 0;
	
}
