#include <iostream>

using namespace std;
// 11060 점프 점프

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	int arr[1001];
	int d[1001] = { 0, };
	
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	for(int i = 1; i <= N; i++){
		if (d[i] == 0 && i != 1)	continue;
		
		for(int j = 1; j <= arr[i]; j++){
			
			if (i + j > N)	continue;
			if (d[i + j] == 0)	d[i + j] = d[i] + 1;
			else	d[i + j] = min(d[i + j], d[i] + 1);	
			
		}	
	}
	
 	if (d[N] == 0 && N != 1)	cout << "-1";
	else	cout << d[N];
	
	return 0;
	
}
