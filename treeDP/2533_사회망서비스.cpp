#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 2533 사회망 서비스

int N;
int INF = 1000000000;
int d[1000001][2] = { 0, };
bool visited[1000001] = { false, };

vector<int> V[1000001];

int dfs(int idx, int k){
	
	if (d[idx][k] != -1)	return d[idx][k];
	
	visited[idx] = true;
	if (k == 0){//얘가 얼리어답터가 아니면 무조건 자식들은 얼리어답터여야함 
		d[idx][k] = 0;
		for(auto next : V[idx]){
			if (visited[next])	continue;
			
			d[idx][k] += dfs(next, 1);
		}	
	}
	else{//얼리어답터면 자식이 뭐든 상관없음 
		d[idx][k] = 1;//자기 포함
		for(auto next : V[idx]){
			if (visited[next])	continue;
			
			d[idx][k] += min(dfs(next, 0), dfs(next, 1));
			
		}
	}
	
	visited[idx] = false;
	return d[idx][k];
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i < N; i++){
		int a, b;	cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	for(int i = 1; i <= N; i++){
		d[i][0] = d[i][1] = -1;
	}
	
	cout << min(dfs(1, 0), dfs(1, 1));
	
	return 0;

}
