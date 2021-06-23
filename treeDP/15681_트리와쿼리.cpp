#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 15681 Æ®¸®¿Í Äõ¸®

int N, R, Q;//N <= 100000
const int MAX_N = 100001;

vector<int> V[MAX_N];

bool visited[MAX_N] = { false, };
int d[MAX_N];

int dfs(int k){
	
	visited[k] = true;

	d[k] = 1;	
	for(int i = 0; i < V[k].size(); i++){
		if (visited[V[k][i]])	continue;
		d[k] += dfs(V[k][i]);
	}
	
	return d[k];
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> R;
	cin >> Q;
	
	for(int i = 1; i < N; i++){
		int a, b;	cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	visited[R] = true;
	dfs(R);
	
	while(Q--){
		
		int tmp;	cin >> tmp;
		
		cout << d[tmp] << "\n";
		
	}
	
	return 0;

}
