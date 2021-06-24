#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 2565 전깃줄
// LIS 알고리즘?
 
class Line{
public:
	int l, r;
	Line(int l, int r){
		this->l = l;
		this->r = r;
	}
};

bool cmp(Line a, Line b){
	return a.l < b.l;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;	cin >> N;
	vector<Line> V;
	
	for(int i = 0; i < N; i++){
		int a, b;	cin >> a >> b;
		V.push_back(Line(a, b));
	}
	
	sort(V.begin(), V.end(), cmp);
	
	int d[101];
	int ans = 0;
	
//	for(auto tmp : V){
//		
//		cout << tmp.l << " " << tmp.r << endl;
//			
//	}

	d[0] = 1;
	for(int i = 1; i < N; i++){
	
		d[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if (V[i].r > V[j].r){
				d[i] = max(d[i], d[j] + 1);
			}
		}
		
		ans = max(ans, d[i]);
		
	}
	
	cout << N - ans;
	
	return 0;
}
