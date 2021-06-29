#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;
// 17471 �Ը��Ǵ���

int N;
int arr[11];//�α� �� ����
vector<int> V[11];

bool Connect[11][11];
bool Select[11];

int Answer = 987654321;

bool check(){
	
	// ���ù����ֵ��̶� ���� �ȹ��� �ֵ��� ����Ǿ� �ִ���
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
	
	//idx������ ����
	check[idx] = true;
	Q.push(idx);
	
	while(!Q.empty()){
		
		int cur = Q.front();
		Q.pop();
		
		for(int i = 0; i < V[cur].size(); i++){
			int next = V[cur][i];
			if (check[next] || !Select[next])	continue;
			// �̹� ��ǰų� ������ ������ �ƴϸ� �н��ϰ�
			
			check[next] = true; 
			Q.push(next);
		
		}
	}
	
	for(int i = 1; i <= N; i++){
		if (Select[i] && !check[i]){
			//���õ� �ص� ������ �ȵ��ִ��Ÿ�
			return false; 
		}
	}
	
	// ���� ���� �ȵȾֵ鳢�� ����Ǿ��ִ����� Ȯ���ϱ� 
	for(int i = 1; i <= N; i++){
		if (!Select[i]){
			idx = i;
			break;
		}
	}
	
	while(!Q.empty())	Q.pop();//Ȥ�� �𸣴ϱ� �ʱ�ȭ �ѹ� ���ְ�
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
	}//���� �ȹ��� �ص� üũ �ȵ������� 
	
	
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

void divide(int idx, int cnt, int S){//index, ���ݱ��� ���� ��, �� �̾ƾ��ϴ� �� 
	
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
		//���鳢�� ����Ǿ� �ִ��� Ȯ���ϰ� ������ �α� �� ��� 
		 
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
	// ���� �α� ��	
		divide(1, 0, i);
		
	}
	
	if (Answer == 987654321)	cout << "-1";
	else	cout << Answer;
	
	return 0;

}
