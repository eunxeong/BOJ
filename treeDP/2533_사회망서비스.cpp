#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 2533 ��ȸ�� ����

int N;
int INF = 1000000000;
int d[1000001][2] = { 0, };
bool visited[1000001] = { false, };

vector<int> V[1000001];

int dfs(int idx, int k){
	
	if (d[idx][k] != -1)	return d[idx][k];
	
	visited[idx] = true;
	if (k == 0){//�갡 �󸮾���Ͱ� �ƴϸ� ������ �ڽĵ��� �󸮾���Ϳ����� 
		d[idx][k] = 0;
		for(auto next : V[idx]){
			if (visited[next])	continue;
			
			d[idx][k] += dfs(next, 1);
		}	
	}
	else{//�󸮾���͸� �ڽ��� ���� ������� 
		d[idx][k] = 1;//�ڱ� ����
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
