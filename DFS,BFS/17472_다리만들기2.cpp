#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
// 17472 다리 만들기 2

int N, M;
int arr[11][11];
bool visited[11][11];
int landN[11][11];
int dt[11][11];
int p[7];

int cnt;
int total = 0;

int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

class Bridge{
public:
	int a, b;
	int cost;
	Bridge(int a, int b, int cost){
		this->a = a;
		this->b = b;
		this->cost = cost;
	}
	
	bool operator <(Bridge &Bridge){
		return this->cost < Bridge.cost;
	}
};

vector<Bridge> V;

void dfs(int x, int y){
	// 섬번호 붙이기
	 
	if (visited[x][y])	return;
	visited[x][y] = true;
	landN[x][y] = total;
	cnt++;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		
		if (visited[nx][ny] || arr[nx][ny] == 0)	continue;
		
		dfs(nx, ny);
	
	}
}

void distance(int a, int b){
	
	// (a, b)를 네가지 방향으로 전부 직진했을 때 만나는 섬을 찾고
	// 그 섬까지의 거리 [p][q] 갱신
	
	int num = landN[a][b];
	
	for(int i = 0; i < 4; i++){
		
		int x = a;
		int y = b;
		
		int d = -1;
		
		while(1){
			
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];	
			
			d++;
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)	break;
			if (d < 2 && arr[nx][ny] == 1)	break;//다리 아직 2안되는데 육지만나면 끝 
			
			if (arr[nx][ny] == num)	break;
			
			if (arr[nx][ny] == 1 && landN[nx][ny] != num){
				// 육지 그 섬이 출발한 섬이 아니라면
//				if (num == 1 && landN[nx][ny] == 5){
//					cout << "왜?" << a << " " << b << endl;
//				}
//				
//				if (dt[num][landN[nx][ny]] == -1){
//					dt[num][landN[nx][ny]] = d;
//					dt[landN[nx][ny]][num] = d;
//				}
//				else{
//					dt[num][landN[nx][ny]] = min(dt[num][landN[nx][ny]], d);
//					dt[landN[nx][ny]][num] = dt[num][landN[nx][ny]];
//				}
				
				V.push_back(Bridge(num, landN[nx][ny], d));
				
				break;
			}
			
			
			x = nx;
			y = ny;
			
		}
		
	}
}

int getP(int x){
	if (p[x] == x)	return x;
	return p[x] = getP(p[x]);
}

void unionP(int a, int b){
	a = getP(a);
	b = getP(b);
	if (a < b)	p[b] = a;
	else	p[a] = b;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)	cin >> arr[i][j];
	}
	
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (!visited[i][j] && arr[i][j] == 1){
				total++;
				cnt = 0;
				dfs(i, j);
				
			}
		}
	}
	
	memset(dt, -1, sizeof(dt));
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (landN[i][j] != 0){
				distance(i, j);		
			}
		}
	}
	
	for(int i = 1; i <= total; i++)	p[i] = i;
	
	int Answer = 0;
	int cot = 0;
	
	sort(V.begin(), V.end());
	
	for(int i = 0; i < V.size(); i++){
		
		if (getP(V[i].a) != getP(V[i].b)){
			unionP(V[i].a, V[i].b);
			Answer += V[i].cost;
			cot++;
		}
		
		if (cot == total - 1)	break;
		
	}
	
	for(int i = 2; i <= total; i++){
		if (getP(i) != getP(1))	Answer = 0;
	}
	
//	for(int i = 1; i <= total; i++)	cout << p[i] << " ";
//	cout << endl;
	if (Answer == 0)	cout << "-1";
	else	cout << Answer;
	
//	cout << endl;
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			cout << landN[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
//	
//	for(int i = 1; i <= total; i++){
//		for(int j = 1; j <= total; j++){
//			cout << dt[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	return 0;

}
