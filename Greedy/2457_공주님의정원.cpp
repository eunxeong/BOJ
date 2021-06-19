#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
// 2457 공주님의 정원

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	
	vector<pair<int, int> > V;
	
	for(int i = 0; i < N; i++){
		pair<int, int> a, b;
		cin >> a.first >> a.second >> b.first >> b.second;//MMdd
		V.push_back( {a.first * 100 + a.second, b.first * 100 + b.second });
	}
	
	sort(V.begin(), V.end());
	
	int idx = -1;//벡터 여기까지 확인 했다는 뜻 
	int temp = 0;//마지막까지 꽃이 피어있는 날짜 
	int result = 0;
	
	// 3월 1일부터 11월 30일
	for(int i = 301; i <= 1130 && idx < N; i = temp){
		bool flag = false;
		idx++;
		
		for(int j = idx; j < V.size(); j++){
			
			if (V[j].first > i)	break;
			
			if (temp < V[j].second){
				temp = V[j].second;
				idx = j;
				flag = true;
			}
		}
		
		if (flag)	result++;
		else{
			cout << 0 << "\n";
			return 0;
		}
	}
	
	cout << result << "\n";
	return 0;	

}
