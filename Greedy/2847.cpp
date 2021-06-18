#include <iostream>

using namespace std;
// 2847 게임을 만든 동준이

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[101];
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	int Answer = 0;
	for(int i = N - 2; i >= 0; i--){
		if (arr[i] < arr[i + 1])	continue;
		
		int tmp = arr[i + 1] - 1;
		int k = arr[i] - tmp;
		
		Answer += k;
		arr[i] = tmp;
	}

	cout << Answer;
	
	return 0;
	
}
