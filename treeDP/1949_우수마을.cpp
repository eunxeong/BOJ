#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
// 1949 우수 마을

int N;
const int MAX_N = 10001;
vector<int> V[MAX_N];

bool visited[MAX_N];
int d[MAX_N][2];//[0]일반마을일때 [1]우수마을일때
int arr[MAX_N];

int dfs(int idx, int k){
	
//	if (visited[idx])	return d[idx][k];
	
	if (d[idx][k] != 0)	return d[idx][k];
	visited[idx] = true;
	
	if (k == 1){//지금 들렸으면 인접마을은  절대 안들린 
		d[idx][k] = arr[idx];
		int tmp = 0;
		for(int i = 0; i < V[idx].size(); i++){
			if (visited[V[idx][i]])	continue;
			tmp += dfs(V[idx][i], 0);
		}
		d[idx][k] += tmp;
	}
	else{
		d[idx][k] = 0;
		int tmp = 0;
		for(int i = 0; i < V[idx].size(); i++){
			if (visited[V[idx][i]])	continue;	
			
			tmp += max(dfs(V[idx][i], 0), dfs(V[idx][i], 1));
		}
		d[idx][k] += tmp;
	}
	
	visited[idx] = false;
	return d[idx][k];
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	for(int i = 1; i < N; i++){
		int a, b;	cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);	
	}

	memset(visited, false, sizeof(visited));
	memset(d, 0, sizeof(d));
	int tmp1 = dfs(1, 0);
	
	memset(visited, false, sizeof(visited));
	memset(d, 0, sizeof(d));
	int tmp2 = dfs(1, 1);
	
	cout << max(tmp1, tmp2) << "\n"; 
	
	return 0;	
}
