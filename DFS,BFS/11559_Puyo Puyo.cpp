#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
// 11559 Puyo Puyo

int N, M, cnt;
char map[13][7];
bool visited[13][7];

bool bomb[75] = { false, };//���� ��ȣ�� true

vector<pair<int, int> > V;
vector<pair<int, int> > vt;//���� �� �ִ��� Ȯ���� �� ��� 

int Answer = 0;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool comp(pair<int, int> p1, pair<int, int> p2){
	return p1.first > p2.first;	
}

void dfs(int x, int y){
	
	if (visited[x][y])	return;
	
	visited[x][y] = true;
	vt.push_back(make_pair(x, y));
	
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		if (visited[nx][ny])	continue;
		
		if (map[x][y] == map[nx][ny])	dfs(nx, ny);
		
	}

}

bool canBomb(){
	
	memset(visited, false, sizeof(visited));
	V.clear();
	
	bool T = false;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (map[i][j] == '.')	continue;
			
			V.push_back(make_pair(i, j));//�������� ���� ���� ���� ĳ���� �ִ� �� ����	
			if (visited[i][j])	continue;
			vt.clear();
			dfs(i, j);
		
			if (vt.size() >= 4){
				T = true;
				for(int k = 0; k < vt.size(); k++){
					map[vt[k].first][vt[k].second] = '.';
				}
				
			}
			
		}
	}
	
	return T;
	
}

void Falling(){
	
	sort(V.begin(), V.end(), comp);
	
	for(int i = 0; i < V.size(); i++){
		int x = V[i].first;
		int y = V[i].second;
		
		if (map[x][y] == '.')	continue;//�������ֿ����� �н� 
	
		int nx = x;
		while(1){
			
			int next = nx + 1;
			if (next == N)	break;
			
			if (map[next][y] != '.')	break;
			else {
				map[next][y] = map[nx][y];
				map[nx][y] = '.';
			}
			
			nx = next;
			
		}
		
//		map[nx][y] = map[x][y];
//		map[x][y] = '.';
		
	}
	
	
}

void Solve(){
	
	while(1){
		if (!canBomb())	break;;
		Answer++;
		
		Falling();		 
	
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	N = 12;
	M = 6;
	
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < M; j++){
			map[i][j] = s[j];
		}
	}


	Solve();

//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
	
	cout << Answer;
	return 0;
	
}
