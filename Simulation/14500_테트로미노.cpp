#include <iostream>
#include <string.h>

using namespace std;
// 14500 테트로미노

int N, M;//4 <= <= 500
int arr[501][501];
int Answer = 0;
int cnt;

int dir[19][3][2] = { { {1, 0}, {0, 1}, {1, 1} },//1
					  { {0, 1}, {0, 2}, {0, 3} },//2
					  { {1, 0}, {2, 0}, {3, 0} },
					  { {1, 0}, {2, 0}, {2, 1} },//3
					  { {0, 1}, {-1, 1}, {-2, 1} },
					  { {1, 0}, {0, 1}, {0, 2} },
					  { {1, 0}, {1, 1}, {1, 2} },
					  { {0, 1}, {1, 1}, {2, 1} },
					  { {1, 0}, {2, 0}, {0, 1} },
					  { {0, 1}, {0, 2}, {-1, 2} },
					  { {0, 1}, {0, 2}, {1, 2} },
					  { {1, 0}, {1, 1}, {2, 1} },//4
					  { {1, 0}, {0, 1}, {-1, 1} },
					  { {0, 1}, {-1, 1}, {-1, 2} },
					  { {0, 1}, {1, 1}, {1, 2} },
					  { {0, 1}, {0, 2}, {1, 1} },//5
					  { {0, 1}, {-1, 1}, {0, 2} },
					  { {1, 0}, {2, 0}, {1, 1} },
					  { {-1, 1}, {0, 1}, {1, 1} } };

bool inArea(int x, int y){
	if (x < 0 || x >= N || y < 0 || y >= M)	return false;
	else	return true;
}

int allcase(int x, int y, int k){
	
	int tmp = arr[x][y];

	for(int i = 0; i < 3; i++){
		int nx = x + dir[k][i][0];
		int ny = y + dir[k][i][1];
		
		if (!inArea(nx, ny))	return -1;
		else	tmp += arr[nx][ny];
	
	}
	
	return tmp;
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 19; k++){
				Answer = max(Answer, allcase(i, j, k));
			}
			
		}
	}
	
	cout << Answer;
	return 0;

}
