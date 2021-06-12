#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
// 2610 회의준비

//int p[101];
bool check[101] = { false, };
int N, M;

//int getP(int x){
//	if (x == p[x])	return x;
//	return p[x] = getP(p[x]);
//}
//
//void unionP(int a, int b){
//	a = getP(a);
//	b = getP(b);
//	if (a < b)	p[b] = a;
//	else	p[a] = b;
//}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	int INF = 1000000000;
	int arr[101][101];
	
	for(int i = 1; i <= N; i++){
//		p[i] = i;
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
//		unionP(a, b);
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][k] + arr[k][j] < arr[i][j])	arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	
	vector<int> V;
	
	for(int i = 1; i <= N; i++){
		
		if (check[i])	continue;
		
		queue<int> Q;
		Q.push(i);
		for(int j = 1; j <= N; j++){
			if (i != j && arr[i][j] != INF)	Q.push(j);
		}
		
		int cur = INF;
		int ans;
		
		if (Q.size() == 1){
			V.push_back(i);
			continue;
		}
		
		while(!Q.empty()){
			
			int idx = Q.front();
			check[idx] = true;
			Q.pop();
			
			int tmp = 0;
			for(int j = 1; j <= N; j++){
				if (idx != j && arr[idx][j] != INF){
					tmp = max(arr[idx][j], tmp);
				}
			}
			
			if (cur > tmp){
				cur = tmp;
				ans = idx;
			}
			
		}
		
		V.push_back(ans);
		
	}
	
	cout << V.size() << "\n";
	sort(V.begin(), V.end());
	for(int i = 0; i < V.size(); i++)	cout << V[i] << "\n";
	
	return 0;
	
}
