#include <iostream>
#include <cstring>

using namespace std;
// 1316 �׷� �ܾ� üĿ

int N;
string str[101];
int Answer = 0;
bool check[27];

int finding(string st, int idx){
// st���� idx���� �������� �ش� ���ڿ��� ������ Ȯ��
	char ch = st[idx];
	int len = st.length();
	for(int i = idx + 1; i < len; i++){
		if (st[i] != ch)	return i - 1;
	}
	
	return len;
	
}

bool func(int idx){
	
	string s = str[idx];
	int len = s.length();
	int p = 0;
	while(p < len){
		
		int k = s[p] - 97;
		if (check[k])	return false;
		
		check[k] = true;
		//�׸��� �� ������ ���� ����� Ȯ���ϰ�
		//idx �ű�� �̵� 
		p = finding(s, p) + 1;
	
	}
	
	return true;
		
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)	cin >> str[i];
	
	for(int i = 0; i < N; i++){
		
		memset(check, false, sizeof(check));
		if (func(i))	Answer++;//i��° ���ڿ��� �׷�ܾ ������ 
		
				
	}
	
	cout << Answer;
	
	return 0;
	
}
