#include <iostream>
#include <vector>
 
using namespace std;

// 13424 ��� ����

int N, M;
int f;
vector<int> fd;//ģ���� ��ġ

int arr[101][101];
int INF = 1000000000;

void Input(){

	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
			
	}
	
	fd.clear();
	cin >> f;
	for(int i = 0; i < f; i++){
		int tmp;	cin >> tmp;
		fd.push_back(tmp);
	}
}

void Floyd(){
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
}

int Solve(){
	
	int Answer = INF;
	int num;
	
	for(int i = 1; i <= N; i++){
		
		int tmp = 0;
		for(int j = 0; j < fd.size(); j++){
			int cur = fd[j];
			if (cur != i){//Ȥ�� �𸣴ϱ� ������Ұ� ���� ��ġ�� ���� ���� 
				tmp += arr[cur][i];
			}
		}
		
		if (tmp < Answer){
			Answer = tmp;
			num = i;
		}
		
	}
	
	return num;
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int T;	cin >> T;
	while(T--){
		Input();	
		Floyd();
		cout << Solve();
		cout << "\n";
	}
	
	return 0;
	
}
