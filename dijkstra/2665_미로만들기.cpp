#include <iostream>
#include <queue>

using namespace std;
// 2665 ¹Ì·Î ¸¸µé±â

int N;
int map[51][51];
bool visited[51][51] = { false, };
int d[51][51];
int INF = 1000000000;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
priority_queue<pair<int, pair<int, int> > > pq;//¹Ù²Û ¼ö * -1, <ÁÂÇ¥> 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < N; j++){
			d[i][j] = INF;
			map[i][j] = s[j] - '0';
		}
	}
	
	d[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));
	
	
	while(!pq.empty()){
		
		int dt = pq.top().first * -1;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		visited[x][y] = true;
		pq.pop();
		
		if (d[x][y] < dt)	continue;
		
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
		
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)	continue;
				
			int next = dt;
			if (map[nx][ny] == 0)	next++;
			
			if (d[nx][ny] < next || visited[nx][ny])	continue;
			d[nx][ny] = next;
			pq.push(make_pair(-next, make_pair(nx, ny)));
		
		}
		
	}
	
	cout << d[N - 1][N - 1];
	
	return 0;
	
}
