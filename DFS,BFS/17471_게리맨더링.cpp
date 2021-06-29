#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;
// 17471 게리맨더링

int N;
int arr[11];//인구 수 저장
vector<int> V[11];

bool Connect[11][11];
bool Select[11];

int Answer = 987654321;

bool check(){
	
	// 선택받은애들이랑 선택 안받은 애들이 연결되어 있는지
	bool check[11];
	queue<int> Q;
	memset(check, false, sizeof(check));
	
	int idx;
	for(int i = 1; i <= N; i++){
		if (Select[i]){
			idx = i;
			break;
		}
	}
	
	//idx번부터 시작
	check[idx] = true;
	Q.push(idx);
	
	while(!Q.empty()){
		
		int cur = Q.front();
		Q.pop();
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i];
			if (check[next] || !Select[next])	continue;
			// 이미 들렷거나 선택한 구역이 아니면 패스하고
			
			check[next] = true; 
			Q.push(next);
		
		}
	}
	
	for(int i = 1; i <= N; i++){
		if (Select[i] && !check[i]){
			//선택된 앤데 연결이 안돼있던거면
			return false; 
		}
	}
	
	// 이제 선택 안된애들끼리 연결되어있는지도 확인하기 
	for(int i = 1; i <= N; i++){
		if (!Select[i]){
			idx = i;
			break;
		}
	}
	
	while(!Q.empty())	Q.pop();//혹시 모르니까 초기화 한번 해주고
	memset(check, false, sizeof(check));
	
	Q.push(idx);
	check[idx] = true;
	
	while(!Q.empty()){
		
		int cur = Q.front();
		Q.pop();
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i];
			if (check[next] || Select[next])	continue;
			
			check[next] = true;
			Q.push(next);
		}
	}
	
	for(int i = 1; i <= N; i++){
		if (!Select[i] && !check[i])	return false;
	}//선택 안받은 앤데 체크 안돼있으면 
	
	
	return true;
	
}

void countN(){
	
	int a = 0, b = 0;
	
	for(int i = 1; i <= N; i++){
		if (Select[i])	a += arr[i];
		else	b += arr[i];
	}
	
	Answer = min(Answer, abs(a - b));
	
}

void divide(int idx, int cnt, int S){//index, 지금까지 뽑은 수, 총 뽑아야하는 수 
	
	if (cnt == S){
//		for(int i = 1; i <= N; i++){
//			if (Select[i])	cout << i << " ";
//		}
//		cout << " | ";
//		for(int i = 1; i <= N; i++){
//			if (!Select[i])	cout << i << " ";
//		}
//		cout << endl;
		
		if (check())	countN();
		//지들끼리 연결되어 있는지 확인하고 맞으면 인구 수 계산 
		 
		return;
	}
	
	for(int i = idx; i <= N; i++){
		if (Select[i])	continue;
		
		Select[i] = true;
		divide(i + 1, cnt + 1, S);
		Select[i] = false;
		
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	
	for(int i = 1; i <= N; i++){
		int tmp;	cin >> tmp;
		
		for(int j = 0; j < tmp; j++){
			int wh;	cin >> wh;
			V[i].push_back(wh);
			V[wh].push_back(i);
		}		
		
	}
	
	memset(Select, false, sizeof(Select));
	for(int i = 1; i <= N / 2; i++){
	// 뽑을 인구 수	
		divide(1, 0, i);
		
	}
	
	if (Answer == 987654321)	cout << "-1";
	else	cout << Answer;
	
	return 0;

}
