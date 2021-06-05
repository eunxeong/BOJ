#include <iostream>
#include <vector>

using namespace std;
// 5567 결혼식

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	vector<int> V[501];
	
	for(int i = 0; i < M; i++){
		int a, b;	cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);	
		
	}
	
	bool check[501] = { false, };
	
	check[1] = true;
	for(int i = 0; i < V[1].size(); i++){
		check[V[1][i]] = true;
	}
	
	int Answer = V[1].size();
	
	for(int i = 0; i < V[1].size(); i++){
		int fr = V[1][i];//친구번호
			
		for(int j = 0; j < V[fr].size(); j++){
			int next = V[fr][j];
			if (!check[next]){
				Answer++;
				check[next] = true;
			}
		}
	}

	cout << Answer;
	
	return 0;
	
}
