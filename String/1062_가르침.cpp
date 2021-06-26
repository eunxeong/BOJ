#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>

using namespace std;
// 1062 가르침

int N, K;
int words[51] = { 0, };

int learn = 0;
int Answer = 0;

void func(int idx, int cnt){//0~26중에 뭐배울차롄지 / 배운 단어 개수 
	
	if (cnt == K){
		int tmp = 0;
		for(int i = 0; i < N; i++){
			if ((learn | words[i]) == learn)	tmp++;
		}
		
		Answer = max(Answer, tmp);
		return;
	}
	
	for(int i = idx; i < 26; i++){
		if ((learn & (1 << i)) == 0){
		// 안배운거면
			learn |= (1 << i);	
			func(i + 1, cnt + 1);
			learn &= ~(1 << i);
		}
	}
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	learn |= 1 << ('a' - 'a');//shift 연산 
	learn |= 1 << ('c' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		
		for(int j = 0; j < s.length(); j++){//size보다 length가 더 빠른가 
			words[i] |= (1 << (s[j] - 'a'));
		}
		
	}
	
	if (K < 5)	Answer = 0;
	else if (K == 26)	Answer = N;
	else{
		func(0, 5);
	}
	
	cout << Answer;
	
	return 0;

}
