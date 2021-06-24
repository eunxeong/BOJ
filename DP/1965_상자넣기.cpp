#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// 1965 상자 넣기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	vector<int> V;
	
	for(int i = 0; i < N; i++){
		int tmp;	cin >> tmp;
		V.push_back(tmp);
	}
	
	int d[1001];
	
	int ans = 0;
	d[0] = 1;
	for(int i = 1; i < N; i++){
		d[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if (V[i] > V[j]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
		
		ans = max(ans, d[i]);
	}
	
	cout << ans;
	return 0;

}
