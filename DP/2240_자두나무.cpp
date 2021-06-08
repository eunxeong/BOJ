#include <iostream>
#include <cstring>

using namespace std;
// 2240 �ڵγ���

int T, W;
int arr[1001];
int d[3][1001][31];//��ġ, ��, �̵� Ƚ�� 

int func(int tree, int idx, int move){
//���� �ִ� ����, ��, �̵� Ƚ��
	// �������
	if (idx > T)	return 0;
	 
	int &res = d[tree][idx][move];
	if (res != -1)	return res;
	
	if (arr[idx] == tree){//���� �ִ� ��ġ���� �ڵΰ� �������� 
		if (move < W){
			//���� ������ �� �ִٸ�
			return d[tree][idx][move] = max(1 + func(tree, idx + 1, move), func(3 - tree, idx + 1, move + 1));
			//�ȿ�����(�׷��� �ϳ� ����), ������ ��� 
		}
		else{//������ �� ������ ������ �� ��� 
			return d[tree][idx][move] = 1 + func(tree, idx + 1, move);
		}
	}
	else{//�ݴ��ʿ��� �������ٸ� 
		if (move < W){
			// ������ �� �־ �������� ���� or �ȿ������� ������ 
			return d[tree][idx][move] = max(1 + func(3 - tree, idx + 1, move + 1), func(tree, idx + 1, move));
		}
		else	return d[tree][idx][move] = func(tree, idx + 1, move);
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T >> W;
	
	for(int i = 1; i <= T; i++)	cin >> arr[i];
	
	memset(d, -1, sizeof(d)); 
	cout << func(1, 1, 0);
	
	return 0;	
	 
}
