#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
// 10610

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	string s;	cin >> s;
	vector<int> V;
	
	bool flag = false;
	int tmp = 0;
	
	for(int i = 0; i < s.length(); i++){
		int k = s[i] - '0';
		
		if (k == 0)	flag = true;
		
		tmp += k;
		V.push_back(k);
	}
	
	
	if (tmp % 3 == 0 && flag){
		sort(V.begin(), V.end(), cmp);
		for(auto i : V)	cout << i;		
		
	}
	else	cout << "-1";
	
	return 0;
	
}
