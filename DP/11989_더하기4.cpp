#include <iostream>

using namespace std;
// 15989 1, 2, 3 ���ϱ� 4 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d[10001][4] = { 0, };
	
	d[1][1] = 1;
	d[2][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	
	/* d[i][j] : i�� ���� �� ���������� ���� ���� j�� ���
		�̷��� 3������ ������ ����ϸ� �ߺ��Ǵ� ���  *(1, 2) (2, 1)����*
		�� �����ϰ� ���� �� �ִ�. */
		 
	for(int i = 4; i <= 10000; i++){
		
		d[i][1] += d[i - 1][1];
		d[i][2] += d[i - 2][1] + d[i - 2][2];
		d[i][3] += d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
		
	}
	
	int T;
	cin >> T;
	while(T--){
		
		int cur;	cin >> cur;
		cout << d[cur][1] + d[cur][2] + d[cur][3] << "\n";	
		
	}
	
	return 0;
	
}
