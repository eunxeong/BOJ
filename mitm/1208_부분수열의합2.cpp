#include <iostream>
#include <map>
#include <vector>

using namespace std;
// 1208 부분수열의 합 2

int N, M, S;
vector<int> V;
map<int, int> mp;
long long int answer = 0;

void dfsLeft(int idx, int sum){
	
	if (idx == M){
		mp[sum]++;	return;
	}
	
	dfsLeft(idx + 1, sum);
	dfsLeft(idx + 1, sum + V[idx]);
}

void dfsRight(int idx, int sum){
	
	if (idx == N){
		answer += mp[S - sum];
		// 5를 만들어야하는데 지금 3까지 만들었다면 아까 2가 나온 횟수만큼이 정답
		return;
	}
	
	dfsRight(idx + 1, sum);
	dfsRight(idx + 1, sum + V[idx]);
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	V.resize(N);
	for(int i = 0; i < N; i++)	cin >> V[i];
	
	M = N / 2;
	dfsLeft(0, 0);
	dfsRight(M, 0);
	
	if (S == 0)	answer--;
	
	cout << answer;
	return 0;
	
}
