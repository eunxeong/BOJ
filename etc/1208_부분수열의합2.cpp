#include <iostream>
#include <map>
#include <vector>

using namespace std;
// 1208 �κм����� �� 2

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
		// 5�� �������ϴµ� ���� 3���� ������ٸ� �Ʊ� 2�� ���� Ƚ����ŭ�� ����
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
