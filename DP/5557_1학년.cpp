#include <iostream>
#include <string.h>

using namespace std;
// 5557 1�г�

int N;
int arr[101];
long long d[101][21] = { 0, };

void func(int idx){
	
	for(int i = 0; i <= 20; i++){
		
		if (d[idx - 1][i] != 0){
			
			// i�� ���� ���� ���ڴϱ�
			if (i + arr[idx] <= 20){
				d[idx][i + arr[idx]] += d[idx - 1][i];
			}
			
			if (i - arr[idx] >= 0){
				d[idx][i - arr[idx]] += d[idx - 1][i];
			}
			
		}
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	d[1][arr[1]] = 1;//ù��°��, arr[1] ���� �� ����Ǽ� = 1 
	
	for(int i = 2; i < N; i++){
		func(i);	
	}

	cout << d[N - 1][arr[N]];
	
	return 0;
	
}
