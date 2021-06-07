#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
// 2668 ���ڰ���

int N;
int arr[101];
bool visited[101] = { false, };
bool ans[101] = { false, };
bool check[101] = { false, };
 
//queue<int> Q;//�Ź� �����ϱ�. �湮�� �ε��� �ֱ� 

vector<int> V;
vector<int> Answer;//������ �͵� �ְ� ���߿� �����ؼ� ��� 

void dfs(int idx){
	
	if (visited[idx])	return;
	
	visited[idx] = true;
	V.push_back(idx);
	
	check[arr[idx]] = true;	
	
	dfs(arr[idx]);
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)	cin >> arr[i];
		
	for(int i = 1; i <= N; i++){
		if (ans[i])	continue;
		
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(visited));
		
		dfs(i);
		// q1�� �ִ°͵� ���� check������ ����
		
		bool T = true;
	
		for(int i = 0; i < V.size(); i++){
		
			if (!check[V[i]])	T = false;
		
		}
		
		if (T){
			for(int i = 0; i < V.size(); i++){
				ans[V[i]] = true;
				Answer.push_back(V[i]);
			}
		}
		
		V.clear();
		
	}

	sort(Answer.begin(), Answer.end());
	cout << Answer.size() << "\n";
	for(int i = 0; i < Answer.size(); i++){
		cout << Answer[i] << "\n";
	}
	
	return 0;
	
}
