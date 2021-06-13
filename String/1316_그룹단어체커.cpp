#include <iostream>
#include <cstring>

using namespace std;
// 1316 그룹 단어 체커

int N;
string str[101];
int Answer = 0;
bool check[27];

int finding(string st, int idx){
// st에서 idx부터 언제까지 해당 문자열이 오는지 확인
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
		//그리고 이 문자의 끝이 어딘지 확인하고
		//idx 거기로 이동 
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
		if (func(i))	Answer++;//i번째 문자열이 그룹단어가 맞으면 
		
				
	}
	
	cout << Answer;
	
	return 0;
	
}
