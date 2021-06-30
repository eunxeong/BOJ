#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 1450 ���� ����

int N, M, C;
vector<long long> V;
vector<long long> m;
long long answer = 0;

void dfsLeft(int idx, long long sum){
	
	if (sum > C)	return;
	if (idx == M){
		m.push_back(sum);
		return;
	}
	
	dfsLeft(idx + 1, sum);
	dfsLeft(idx + 1, sum + V[idx]);
}

void dfsRight(int idx, long long sum){
	
	if (sum > C)	return;
	if (idx == N) {
		int k = upper_bound(m.begin(), m.end(), C - sum) - m.begin();//�� ���� �� �ִ� ���� 
		answer += k;
		return;
	}
	
	dfsRight(idx + 1, sum);
	dfsRight(idx + 1, sum + V[idx]);
	
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> C;
	V.resize(N);
	for(int i = 0; i < N; i++)	cin >> V[i];
	
	M = N / 2;
	
	dfsLeft(0, 0);
	sort(m.begin(), m.end());
	dfsRight(M, 0);
	
//	answer--;
	cout << answer;
	
	return 0;
	
}
