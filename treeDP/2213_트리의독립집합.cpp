#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
// 2213 트리의 독립 집합

int N;
int arr[10001];
int d[10001][2];
bool visited[10001];

vector<int> V[10001];
vector<int> ans;

void dfs(int idx){
	
	if (visited[idx]) return;
	
	visited[idx] = true;
	d[idx][0] = 0;
	d[idx][1] = arr[idx];
	
	for(auto next : V[idx]){
		if (visited[next])	continue;
		
		dfs(next);
		d[idx][0] = d[idx][0] + max(d[next][0], d[next][1]);
		d[idx][1] = d[idx][1] + d[next][0];
		
	}
	
}

void trace(int cur, bool isinclude){
	
	visited[cur] = true;
	
	if (isinclude){
		ans.push_back(cur);
		for(auto next : V[cur]){
			if (visited[next])	continue;
			trace(next, false);
		}
	}
	else{
		for(auto next : V[cur]){
			if (visited[next])	continue;	
			
			if (d[next][1] > d[next][0]){
				// 들린게더ㅡ크다면
				trace(next, true);
			}
			else	trace(next, false);
			
		}
		
	}
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
	
	dfs(5);
	cout << max(d[5][0], d[5][1]) << "\n";
	
	memset(visited, false, sizeof(visited));
	
	if (d[5][0] > d[5][1]){
		trace(5, false);	
	}
	else{
		trace(5, true);
	}
	
	sort(ans.begin(), ans.end());
	
	for(auto k : ans){
		cout << k << " ";	
	}
	
	return 0;
}
