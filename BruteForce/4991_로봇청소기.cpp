#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
 
using namespace std;
// 4991 �κ� û�ұ�

int N, M;
char arr[21][21];
int d[11][11]; 
bool visited[21][21];
bool checked[11];

vector<pair<int, int> > V;
int dcnt;
int tmpS;
int Answer = 0;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int startD(int a, int b, int idx){//������ġ�� a, b���� V[idx]���� �󸶳� �ɸ����� 
	
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	
	memset(visited, false, sizeof(visited));
	visited[a][b] = true;
	
	int k = 0;
	
	while(!Q.empty()){
		
		int q_size = Q.size();
		k++;
		
		while(q_size--){
			
			int x = Q.front().first;
			int y = Q.front().second;	
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (visited[nx][ny] || arr[nx][ny] == 'x')	continue;
				
				visited[nx][ny] = true;
				if ((nx == V[idx].first) && (ny == V[idx].second)){
					return k;
				}
				
				Q.push(make_pair(nx, ny));
			
			}
			
		}
		
	}
	
	return -1;
	
}

int countD(int a, int b){//V[a] -> V[b] �ִܰŸ� 
	
	if (d[a][b] != -1)	return d[a][b];
	
	queue<pair<int, int> > Q;
	memset(visited, false, sizeof(visited));
	
	Q.push(V[a]);
	visited[V[a].first][V[a].second] = true;
	
	int k = 0;//�Ÿ�����Ұ�
	 
	while(!Q.empty()){
		
		int q_size = Q.size();
		k++;
		
		while(q_size--){
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (visited[nx][ny] || arr[nx][ny] == 'x')	continue;
				
				if ((nx == V[b].first) && (ny == V[b].second)){
					d[a][b] = k;
					d[b][a] = k;
					return k;
				}
				
				visited[nx][ny] = true;
				Q.push(make_pair(nx, ny));
			
			}
		}
		
	}
		
	return d[a][b];	

}

void Func(int start, int cnt){//idx���� �������̰� ���ݱ��� ��ߴ���? 
	
	if (cnt == dcnt){
		Answer = min(Answer, tmpS);
		return;
	}
	
	for(int i = 0; i < dcnt; i++){
		if (checked[i])	continue;
		
		checked[i] = true;
		tmpS += countD(start, i);
		Func(i, cnt + 1);
		tmpS -= countD(start, i);
		checked[i] = false;
	
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		cin >> M >> N;
		if (N == 0 && M == 0)	break;	
		
		int a, b;//start ��ġ 
		V.clear();
		
		for(int i = 0; i < N; i++){
			string str;	cin >> str;
			for(int j = 0; j < M; j++){
				arr[i][j] = str[j];
				if (arr[i][j] == 'o'){
					a = i;
					b = j;	
				}
				else if (arr[i][j] == '*'){
					V.push_back(make_pair(i, j));
				}
			}
		}
		
		dcnt = V.size();
		memset(d, -1, sizeof(d));//a�� �������� b�� �������� �Ÿ� 
		memset(checked, false, sizeof(checked));
		 
		Answer = 100000000;
		
		for(int i = 0; i < dcnt; i++){
			
			//startD�ؼ� �ű�����Ÿ� ���ϰ� �ű⼭���� 		
			tmpS = startD(a, b, i);
			
			if (tmpS == -1){
				Answer = -1;
				break;
			}
			
			checked[i] = true;
			Func(i, 1);
			checked[i] = false;
		}
		
		cout << Answer << "\n";
		
		
	}

	return 0;
	
}
