#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 14267 회사 문화 1

int N, M;
int arr[100001];
vector<int> V[100001];

int total[100001] = { 0, };

void dfs(int idx, int cnt){
	
	for(int i = 0; i < V[idx].size(); i++){
		total[V[idx][i]] = cnt + arr[V[idx][i]];
		dfs(V[idx][i], total[V[idx][i]]);
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	
	int tmp;	cin >> tmp;//-1입력받고 
	for(int i = 2; i <= N; i++){
		cin >> tmp;
		V[tmp].push_back(i); 
	}
 
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		arr[a] = b;
	}

	dfs(1, 0);
	
	for(int i = 1; i <= N; i++)	cout << total[i] << " ";
	
	return 0;
	
}
