#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
// 20291 파일 정리

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<string, int> mp;
	
	int N;	cin >> N;
	for(int i = 0; i < N; i++){
		string s;	cin >> s;
		int k = s.find('.') + 1;
		
		string ext = "";
		for(int j = k; j < s.length(); j++){
			ext += s[j];
		}
		
		mp[ext]++;
		
	}
	
	map<string, int>::iterator iter;
	for(iter = mp.begin(); iter != mp.end(); iter++){
		cout << iter->first << " " << iter->second << "\n";
	}
	
	return 0;

}
