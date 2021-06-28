#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
// 13460 구슬 탈출 2
 
struct Ball{
	int x, y;
	int cot = 0;
};

int N, M;
char arr[11][11];

int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

Ball moving(Ball ball, int d){
	
	Ball next;
	int x = ball.x;
	int y = ball.y;
	
	int cot = 0;
	while(1){
	
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		
		if (arr[nx][ny] == 'O'){
			x = -1;
			y = -1;
			break;
		}
		
		if (arr[nx][ny] == '#')	break;
		
		x = nx;
		y = ny;
		cot++;
	
	}
	
//	cout << x << " " << y << "로이동\n"; 
	next.x = x;
	next.y = y;
	next.cot = cot;
	return next;
	
}

int bfs(Ball curR, Ball curB){
	
	int cnt = 0;
	queue<pair<Ball, Ball> > Q;
	Q.push(make_pair(curR, curB));
	
	while(cnt < 10){
		
		cnt++;
		int q_size = Q.size();
//		cout << endl;
		while(q_size--){
			Ball r = Q.front().first;
			Ball b = Q.front().second;
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				
				Ball nR = moving(r, i);
				Ball nB = moving(b, i);	
				
				if (nB.x == -1 && nB.y == -1)	continue;
				// 파란건 빠지면 안되는데 빠진거니까 패스
				
				if (nR.x == -1 && nR.y == -1)	return cnt;
				// 파란건 안빠졌고 빨간게 빠진거니까 리턴
				
				if (r.x == nR.x && r.y == nR.y && b.x == nB.x && b.y == nB.y)	continue;
				// 둘다 움직인게 똑같으면 할필요 없음
				 
				bool flag = false;
				if (nR.x == nB.x && nR.y == nB.y){
					 
					/* 원래 칸이 어디였고 이런거 다 상관없고
						이동을 더 많이한 애가 늦게온거이기 때문에
						걔 칸만 변경
						이렇게 간단한걸 ㅠ 반례때문에 */
						 
					if (nR.cot > nB.cot){
						//R이 더 많이 움직였음  
						nR.x -= dir[i][0];
						nR.y -= dir[i][1];
						
					}
					else{
						nB.x -= dir[i][0];
						nB.y -= dir[i][1];
					}
					
					
//					if (r.x == nR.x && r.y == nR.y){
//						//겹치는데 R은 원래 이자리였으면 B가 온거임
//						nB.x -= dir[i][0];
//						nB.y -= dir[i][1];
//						flag = true;
//					}
//					
//					if (!flag && b.x == nB.x && b.y == nB.y){
//						nR.x -= dir[i][0];
//						nR.y -= dir[i][1];
//						flag = true;
//						
//					}
//					
//					if (!flag && r.x + dir[i][0] == b.x){
//						if (r.y + dir[i][1] == b.y){
//							//이러면 R이 문제라는거
//	//						cout << "R옮겨\n"; 
//							nR.x -= dir[i][0];
//							nR.y -= dir[i][1];
//							flag = true;
//						}
//					}
//					
//					if (!flag && b.x + dir[i][0] == r.x){
//						if (b.y + dir[i][1] == r.y){
//	//						cout << "B옮겨\n"; 
//							nB.x -= dir[i][0];
//							nB.y -= dir[i][1];
//							flag = true;
//						}
//					}
					
					
					
				}
				
				Q.push(make_pair(nR, nB));
//				cout << nR.x << " " << nR.y << "로 이동 \n\n"; 
			}
		}
		
	}
	
	return -1;
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	int bx, by, rx, ry;
	
	Ball r, b;
	
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		for(int j = 0; j < M; j++){
		
			arr[i][j] = s[j];
			if (arr[i][j] == 'B'){
				b.x = i;
				b.y = j;
			}
			else if	(arr[i][j] == 'R'){
				r.x = i;
				r.y = j; 
			}
		}
		
	}
	
	cout << bfs(r, b);
	
	return 0;
	
}
