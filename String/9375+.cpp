#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
// 9375 �мǿ� ���غ�

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	while(T--){
		
		map<string, int> mp;
		vector<int> V;
		long long ans = 1;
	
		int N;	cin >> N;
		for(int i = 0; i < N; i++){
			string s1, s2;	cin >> s1 >> s2;
			mp[s2]++;
		}
		
		map<string, int>::iterator iter; 
		for(iter = mp.begin(); iter != mp.end(); iter++){
			ans *= (iter->second + 1);
		}
		
		// ������ ����Ǽ��� �߰��ؼ� ��ü ����� �� - �ƹ��͵� ������ ���
		cout << ans - 1 << "\n";
		
	}
	
	return 0;
}
