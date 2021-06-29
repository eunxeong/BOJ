#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <queue>
#include <vector>
 
using namespace std;
// 11003 ÃÖ¼Ú°ª Ã£±â

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int L, N;	cin >> N >> L;
	deque<pair<int, int> > dq;
	
	int tmp;	cin >> tmp;
	dq.push_back(make_pair(tmp, 0));
	cout << tmp << " ";
	
	for(int i = 1; i < N; i++){
		cin >> tmp;
		
		int k = dq.front().second;
		if (i - L >= k)	dq.pop_front();
		
		while(!dq.empty()){
			if (dq.back().first < tmp)	break;
			dq.pop_back();
		}
		
		dq.push_back(make_pair(tmp, i));
		
		cout << dq.front().first << " ";
		
	}
	cout << endl;
	
	return 0;
	
}
