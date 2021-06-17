#include <iostream>

using namespace std;
// 13305 주유소

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int maxN = 100001;
	long long int city[maxN];
	long long int dt[maxN];
	int N;
	
	cin >> N;
	dt[1] = 0;
	for(int i = 2; i <= N; i++){
		int tmp;	cin >> tmp;
		dt[i] = tmp + dt[i - 1];
	}
	
	for(int i = 1; i <= N; i++)	cin >> city[i];
	
	int cur = 1;//지금 있는 곳
	int next;//다음 갈 곳
	
	long long int Answer = 0;
	
	while(cur < N){
		
		
		next = cur + 1;
		while(next < N){
			if (city[next] < city[cur])	break;
			next++;
		}
	
		long long int d = dt[next] - dt[cur];
		d *= city[cur];
		
		Answer += d;
		
		cur = next;
	
	}
	
	cout << Answer;
	
	return 0;
}
