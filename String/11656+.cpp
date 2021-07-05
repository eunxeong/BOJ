#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
// 11656 ���̻� �迭 1620 ���¾� ���ϸ� ������ �̴ټ� 15829 Hashing

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
//	string s;	cin >> s;
//	vector<string> V;
//	
//	int len = s.length();
//	for(int i = 0; i < s.length(); i++){
//		
//		V.push_back(s.substr(i, len--));
//		
//	}
//	
//	sort(V.begin(), V.end());
//	for(auto str : V){
//		cout << str << "\n";
//	}
	
//	map<int, string> mp1;
//	map<string, int> mp2;
//	
//	int N, M;	cin >> N >> M;
//	for(int i = 1; i <= N; i++){
//		string s;	cin >> s;
//		mp1[i] = s;
//		mp2[s] = i;
//	}
//	
//	for(int i = 0; i < M; i++){
//		string s;	cin >> s;	
//		if (isdigit(s[0])){
//			int k = stoi(s);
//			
//			cout << mp1[k] << "\n";
//			
//		}
//		else{
//			cout << mp2[s] << "\n";
//		}
//	}
	
	int N;	cin >> N;
	string s;	cin >> s;
	
	long long ans = 0;
	long long M = 1234567891;
	
	for(int i = 0; i < s.length(); i++){
		long long k = s[i];
		k -= 96;
		
		for(int j = 0; j < i; j++){
			k = (k * 31) % M;	
		}
		//pow ���ϱ� ���� �Ѿ���� N ������� ������ �׷��� ������ ����
		 
		long long tmp = k % M;
		
		ans = (ans + tmp) % M;
		
	}
	
	cout << ans;
	return 0;

}
