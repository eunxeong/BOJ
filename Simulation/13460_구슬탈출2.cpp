#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
// 13460 ���� Ż�� 2
 
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
	
//	cout << x << " " << y << "���̵�\n"; 
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
				// �Ķ��� ������ �ȵǴµ� �����Ŵϱ� �н�
				
				if (nR.x == -1 && nR.y == -1)	return cnt;
				// �Ķ��� �Ⱥ����� ������ �����Ŵϱ� ����
				
				if (r.x == nR.x && r.y == nR.y && b.x == nB.x && b.y == nB.y)	continue;
				// �Ѵ� �����ΰ� �Ȱ����� ���ʿ� ����
				 
				bool flag = false;
				if (nR.x == nB.x && nR.y == nB.y){
					 
					/* ���� ĭ�� ��𿴰� �̷��� �� �������
						�̵��� �� ������ �ְ� �ʰԿ°��̱� ������
						�� ĭ�� ����
						�̷��� �����Ѱ� �� �ݷʶ����� */
						 
					if (nR.cot > nB.cot){
						//R�� �� ���� ��������  
						nR.x -= dir[i][0];
						nR.y -= dir[i][1];
						
					}
					else{
						nB.x -= dir[i][0];
						nB.y -= dir[i][1];
					}
					
					
//					if (r.x == nR.x && r.y == nR.y){
//						//��ġ�µ� R�� ���� ���ڸ������� B�� �°���
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
//							//�̷��� R�� ������°�
//	//						cout << "R�Ű�\n"; 
//							nR.x -= dir[i][0];
//							nR.y -= dir[i][1];
//							flag = true;
//						}
//					}
//					
//					if (!flag && b.x + dir[i][0] == r.x){
//						if (b.y + dir[i][1] == r.y){
//	//						cout << "B�Ű�\n"; 
//							nB.x -= dir[i][0];
//							nB.y -= dir[i][1];
//							flag = true;
//						}
//					}
					
					
					
				}
				
				Q.push(make_pair(nR, nB));
//				cout << nR.x << " " << nR.y << "�� �̵� \n\n"; 
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
