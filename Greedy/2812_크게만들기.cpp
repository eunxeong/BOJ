#include <iostream>
#include <cstring>
#include <deque>

using namespace std;
// 2812 크게 만들기

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;	cin >> N >> K;
	// 1 <= K < N <= 500,000
	
	// 뒤에꺼 확인 -> 나보다 크면 지워도 됨
	// 나보다 작으면 -> 지우면 안됨
	// 이렇게 간단한게 아니었다.. 그냥 무조건 앞에서부터 오름차순으로 나와야함
	// 그래서 덱 사용 
	
	string num;	cin >> num;
	deque<char> dq;
	
	for(int i = 0; i < num.length(); i++){
		
		while (K && !dq.empty() && (dq.back() < num[i])){
			dq.pop_back();
			K--;
		}
		
		dq.push_back(num[i]);
		
	}

	for(int i = 0; i < dq.size() - K; i++)	cout << dq[i];
	
	return 0;
	
}
