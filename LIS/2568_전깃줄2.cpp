#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
// 2568 전깃줄 - 2

const int MAXN = 500001;

struct Code{
	
	int anum;//연결된 a 번호 
	int ref;//전에꺼. 첫번째면 -1 
	
};

class Line{
public:
	int a, b;
	Line(int a, int b){
		this->a = a;
		this->b = b;
	}
	bool operator <(Line &line){
		return this->a < line.a;	
	}
};

int N;
Code arr[MAXN];
int lis[MAXN][2];
vector<Line> V;

int binarysearch(int left, int right, int target){
	
	int mid;
	
	while(left < right){
		mid = (left + right) / 2;
		
		if (lis[mid][0] == target)	return mid;
		else if	(lis[mid][0] < target)	left = mid + 1;
		else	right = mid;
		
	}
	
	return right;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;	cin >> a >> b;
		V.push_back(Line(a, b));
	}
	
	sort(V.begin(), V.end());
	
	arr[0].anum = V[0].a;
	arr[0].ref = -1;
	
	lis[0][0] = V[0].b;
	lis[0][1] = 0; 
	
	int cnt = 1;
	
	for(int i = 1; i < N; i++){
		
		if (V[i].b > lis[cnt - 1][0]){
			lis[cnt][0] = V[i].b;
			lis[cnt][1] = i;
			
			arr[i].anum = V[i].a;
			arr[i].ref = lis[cnt - 1][1];
			
			cnt++;
		}
		else if	(V[i].b < lis[0][0]){
			lis[0][0] = V[i].b;
			lis[0][1] = i;
			
			arr[i].anum = V[i].a;
			arr[i].ref = -1;
		}
		else{
			int k = binarysearch(0, cnt, V[i].b);
			lis[k][0] = V[i].b;
			lis[k][1] = i;
			
			arr[i].anum = V[i].a;
			arr[i].ref = (k == 0) ? -1 : lis[k - 1][1];
		}
	}

	cout << N - cnt << "\n";
	
	int idx = lis[cnt - 1][1];
	
	bool check[MAXN] = { false, };
	
	while(idx != -1){
		check[arr[idx].anum] = true;
		idx = arr[idx].ref;
	}
	
	for(auto a : V){
		if (!check[a.a])	cout << a.a << "\n";	
	}
	
	return 0;
	
}
