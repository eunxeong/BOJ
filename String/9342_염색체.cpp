#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 9342 ����ü

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	
	while(T--){
		
		string s;	cin >> s;
		int k = s[0];
		if (k > 70){
			cout << "Good\n";
			continue;
		}
		
		int idx = 0;
		if (s[0] == 'A')	idx = 1;//A �������� ���
		
		bool flag = true;
		for(int i = 1; i < s.length(); i++){
			
			if (idx == 0){
				//������ A���;���
				if (s[i] == 'A'){
					idx = 1;
					continue;
				}
				flag = false;
				break;
			}
			
			if (idx == 1){
				// A�� ���Դٴ°Ŵϱ�
				// ���� A���͵� �ǰ� �ƴϸ� F�� �Ѿ����
				if (s[i] == 'A')	continue;
				else if (s[i] == 'F'){
					idx = 2;
					continue;
				}
				flag = false;
				break;
			}
			
			if (idx == 2){
				if (s[i] == 'F')	continue;
				else if (s[i] == 'C'){
					idx = 3;
					continue;
				}
				flag = false;
				break;
			}
				
			if (idx == 3){
				// ���ð� �� ���԰� C�� ��� ���͵� ��
				// �ٵ� C�� �ƴ϶��A, B, C, D, E, F �߿� �ϳ��� ���;���
				
				if (s[i] == 'C')	continue;
				
				if (s.length() - i > 1){
					flag = false;
					break;
				}
				
				int k = s[i];
				if (k > 70){
					flag = false;
					break;
				}
				
			}
		
		}
		
		if (flag)	cout << "Infected!\n";
		else	cout << "Good\n";
		
		
	}


}
