#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 8980 택배
// https://steadev.tistory.com/15 참고
 
class Box{
public:
	int from;
	int to;
	int cnt;
	Box(int from, int to, int cnt){
		this->from = from;
		this->to = to;
		this->cnt = cnt;
	}
};

// 도착지 기준 오름차순 정렬 
bool cmp(Box a, Box b){
	if (a.to == b.to)	a.from > b.from;
	return a.to < b.to;
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, C, M;	cin >> N >> C >> M;
	vector<Box> box;
	for(int i = 0; i < M; i++){
		int a, b, c;	cin >> a >> b >> c;
		box.push_back(Box(a, b, c));
	}
	
	vector<int> left(N + 1, C);//각 마을 들릴 때마다 들 수 있는? 
	sort(box.begin(), box.end(), cmp);
	
	int ans = 0;
	for(auto d : box){
		
		int k = left[d.from];
		for(int i = d.from + 1; i < d.to; i++){
			k = min(k, left[i]);
		}//싣고 가야하는 공간 중 가장 적게 남은
		
		if (d.cnt > k)	d.cnt = k;
		
		ans += d.cnt;
		
		for(int i = d.from; i < d.to; i++)	left[i] -= d.cnt;
		// 이만큼 들고 가야하니까 그만큼 다 빼주고
				
	}
		
	cout << ans;
	return 0;
}
