#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
// 9375 �мǿ� ���غ�

//void choice(int idx, int cnt, int k){
//	//���ݱ��� �� ����, ������ ����	
//	if (cnt == k){
//		int tmp = 1;
//		for(int i = 0; i < total; i++){
//			if (ch[i])	tmp *= V[i];
//		}
//		 
//		ans += tmp;
//		return;
//	}
//	
//	for(int i = idx; i < total; i++){
//		if (ch[i])	continue;//�̹� ���Ÿ� 
//		
//		ch[i] = true;
//		choice(i + 1, cnt + 1, k);
//		ch[i] = false; 
//		
//	}
//	
//} ���� ������ ������ �ʿ� ����Ф� ��ü ����� ������ �ƹ��͵� �������Ÿ� ����ȴ�.. 

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
		
		
		cout << ans - 1 << "\n";
		
	}
	
	return 0;
}
