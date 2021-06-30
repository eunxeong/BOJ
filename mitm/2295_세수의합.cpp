#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
// 2295 세 수의 합
// x, y, z, k가 같아도 되기 때문에 나름 쉬움 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;//<= 1000
	int arr[1001];
	cin >> N;
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	sort(arr, arr + N);
	map<int, int> mp;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mp[arr[i] + arr[j]]++;
		}
	}
	
	for(int k = N - 1; k >= 0; k--){
		
		for(int i = 0; i < N; i++){
			int tmp = arr[k] - arr[i];
			if (mp.count(tmp) > 0){
				cout << arr[k];
				return 0;
			}
		}
	}
	
}

/*
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 

int main() {
	int n; cin >> n; 
	vector<int> v, p; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a; 
		v.push_back(a);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) p.push_back(v[i] + v[j]); 
	sort(p.begin(), p.end()); 
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (binary_search(p.begin(), p.end(), v[i] - v[j])) {
			cout << v[i] << "\n"; 
			return 0; 
		}
	}
}

*/

