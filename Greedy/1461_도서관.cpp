#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
// 1461 도서관

bool cmp(int a, int b){
	return a > b;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;	cin >> N >> M;
	vector<int> v1, v2;//양수, 음수
	 
	for(int i = 0; i < N; i++){
		int tmp;	cin >> tmp;
		if (tmp > 0)	v1.push_back(tmp);
		else	v2.push_back(tmp);
	}
	
	priority_queue<int> Q;
	
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end());
	
	int idx = 0;
	while(idx < v1.size()){
		
		Q.push(v1[idx]);
		idx += M;
		
	}
	
	idx = 0;
	while(idx < v2.size()){
		
		Q.push(-v2[idx]);
		idx += M;
			
	}
	
	int ans = Q.top();
	Q.pop();
	
	while(!Q.empty()){
		ans += Q.top() * 2;
		Q.pop();
	}
	
	cout << ans;
	
	return 0;
	
}
