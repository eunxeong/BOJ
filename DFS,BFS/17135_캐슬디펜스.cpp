#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
// 17135 ĳ�� ���潺

int N, M, D, kill;//k�� �Ź� ���� ���� �� 
int sumE = 0;//���� ��
int Answer = 0;
int enemy;

int map[17][16];
int tmp[17][16];
int tmp2[17][16];

bool Archer[16];
bool visited[17][16];

int dir[3][2] = { { 0, -1}, {-1, 0}, {0, 1} };
vector<int> V;//�ü� ��ġ

void bfs(int p){//�ü� �ִ� position 
	
	int a = N - 1;
	int b = p;//�Ÿ� 1�� ��ġ 

	memset(visited, false, sizeof(visited));
	
	if (tmp[a][b] == 1){
		if (tmp2[a][b] == 1){
			kill++;
			enemy--;
			tmp2[a][b] = 0;
		}
		return;
	}
	
	int dt = 2;
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));

	while(dt <= D && !Q.empty()){
				
		int k = Q.size();	
		while(k--){
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			
			for(int i = 0; i < 3; i++){
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (visited[nx][ny])	continue;
				
				if (tmp[nx][ny] == 1){
					if (tmp2[nx][ny] == 1){
						tmp2[nx][ny] = 0;
						kill++;
						enemy--;
					}
					return;
				}
				
				Q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				
			}	
		}
		dt++;
		
	}
	
}

void Solve(){
	
	V.clear();
	for(int i = 0; i < M; i++){
		if (Archer[i]){
			V.push_back(i);
		}
	}
	
	memcpy(tmp, map, sizeof(map));
	kill = 0;//���� �� 
	enemy = sumE;
	
	
	while(enemy > 0){
		// ĭ�� ���̻� ���� ���� ������ 
		memcpy(tmp2, tmp, sizeof(tmp));
		for(int i = 0; i < 3; i++){
			bfs(V[i]);
		}

		// �ѹ߾� �� ������
		// ���� ���� ��ĭ�� �Ʒ���
		
		memcpy(tmp, tmp2, sizeof(tmp2));
		
		for(int i = N - 1; i >= 0; i--){
			for(int j = 0; j < M; j++){
				if (tmp[i][j] == 0)	continue;
				
				if (i == N - 1)	enemy--;
				else	tmp[i + 1][j] = 1;
		
				tmp[i][j] = 0;
			}
		}
	}
	Answer = max(Answer, kill);
}

void choiceA(int idx, int cnt){
	
	if (cnt == 3){
		Solve();
		return;
	}
	
	for(int i = idx; i < M - 2 + cnt; i++){
		Archer[i] = true;
		choiceA(i + 1, cnt + 1);
		Archer[i] = false;
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> D;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 1)	sumE++;
		}
	}
	
	choiceA(0, 0);//�ü� ����
	
	cout << Answer;
	
	return 0; 

}
