#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>

using namespace std;
// 9205 ���� ���ø鼭 �ɾ��

int N;
int arr[103][103];//�ʿ��� ���� �� ��� 
vector<pair<int, int> > V;//[0]�� �� [N + 1]�� �佺Ƽ�� 


void Input(){
	
	cin >> N;
	V.clear();
	int x, y;	cin >> x >> y;
	V.push_back(make_pair(x, y));
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		V.push_back(make_pair(x, y));
	}
	cin >> x >> y;
	V.push_back(make_pair(x, y));
	
}

void canGo(){
	
	for(int i = 0; i <= N + 1; i++){
		for(int j = i + 1; j <= N + 1; j++){
			int x, y, nx, ny;
			x = V[i].first;
			y = V[i].second;
			nx = V[j].first;
			ny = V[j].second;
			float beer = (abs(x - nx) + abs(y - ny)) / 50;
			int p = (abs(x - nx) + abs(y - ny)) % 50;
			if (beer <= 20){
				if (beer == 20 && p != 0)	continue;
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}
	
}

void Floyd(){
	
	int M = N + 2;
	for(int k = 0; k < M; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < M; j++){
				if (arr[i][k] == 1 && arr[k][j] == 1)	arr[i][j] = 1;
			}
		}
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// ������ �Ÿ����� �÷��̵� �ͼ�?
	int tc;	cin >> tc;
	while(tc--){
		Input();
		memset(arr, 0, sizeof(arr));
		canGo();
		Floyd();
		
		if (arr[0][N + 1] == 1)	cout << "happy\n";
		else	cout << "sad\n";
		
	}
	
	return 0;
	
}
