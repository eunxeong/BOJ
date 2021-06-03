#include <iostream>
#include <vector>

using namespace std;
// 11049 Çà·Ä °ö¼À ¼ø¼­

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	vector<pair<int, int> > V;
	for(int i = 0; i < N; i++){
		int p, q;	cin >> p >> q;
		V.push_back(make_pair(p, q));
	}
	
	int d[501][501] = { 0, };
	
	for(int i = 2; i <= N; i++){//gap
		if (i == 2){
			for(int j = 0; j < N - 1; j++){
				d[j][j + 1] = V[j].first * V[j].second * V[j + 1].second;
			}
			continue;
		}
		
		for(int j = 0; j <= N - i; j++){
			
			int start = j;
			int end = i + j - 1;
			
			d[start][end] = 1000000000;
			for(int k = start; k < end; k++){
				int tmp = V[start].first * V[k].second * V[end].second;	
				d[start][end] = min(d[start][end], d[start][k] + d[k + 1][end] + tmp);
				
			}
			
		}
		
	}
 
	cout << d[0][N - 1];
	
	return 0;
	
}
