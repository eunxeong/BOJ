#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 4659 ��й�ȣ �����ϱ�

// �����̸� true 
bool arr[26] = { 1, 0, 0, 0, 1,
				0, 0, 0, 1, 0,
				0, 0, 0, 0, 1,
				0, 0, 0, 0, 0,
				1, 0, 0, 0, 0, 0 };

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		string s;	cin >> s;	
		if (s == "end")	break;
		
		bool flag1 = false;
		bool flag2 = true;//���� ���ڰ� �ι� ���� ���Դ��� 
		int x = 0;//�����ؼ� ������ �ִ� ���� �� 
		int y = 0;//�����ؼ� ������ �ִ� ���� ��
		 
		for(int i = 0; i < s.length(); i++){
			
			int idx = s[i] - 97;
			if (arr[idx])	flag1 = true;//���� �ϳ� �̻� 
			
			if (i != 0){
				if (s[i] == s[i - 1]){
					if (s[i] != 'e' && s[i] != 'o')	flag2 = false;
				}
			}
			
			if (!flag2)	break;//�� ���ʿ� ����
			
			// ���� ���� ������ ���� �������� �������� 
			if (arr[idx]){
				// �켱 �����̸�
				if (x == 2){
					flag2 = false;
					break;//�տ� �ι� ���� �����ϱ�
				}
				x++;
				y = 0;
			}
			else{
				if (y == 2){
					flag2 = false;
					break;
				}
				y++;
				x = 0;
			}
			
			
		}
		
		cout << "<" << s << "> ";
		if (flag1 && flag2){
			cout << "is acceptable.\n";
		}
		else {
			cout << "is not acceptable.\n";
		}
		
	}

	return 0;
	
}
