#include <iostream>
#include <vector>

using namespace std;
// 1068 Æ®¸®

//struct Node{
//	int left = NULL;
//	int right = NULL;
//};
//
//Node node[51];

int N, K;
vector<int> V[51];
int ans = 0;

void dfs(int idx){
	
	if (idx == K)	return;
	int cnt = 0;
	for(int i = 0; i < V[idx].size(); i++){
		if (V[idx][i] == K)	continue;
		cnt++;
		dfs(V[idx][i]);
	}
	
	if (cnt == 0)	ans++;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int root;
	
	for(int i = 0; i < N; i++){
		int tmp;	cin >> tmp;
		if (tmp == -1)	root = i;
		else	V[tmp].push_back(i);
	}
	cin >> K;
	
	dfs(root);
	cout << ans;
	return 0;
	
}
