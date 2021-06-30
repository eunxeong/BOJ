#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 2467 ���

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
	vector<int> m, p;
	
	for(int i = 0; i < N; i++){
		int tmp;	cin >> tmp;
		if (tmp > 0)	p.push_back(tmp);
		else	m.push_back(tmp);
	}
	
	long long answer = 1999999999;
	long long sum;
	long long x, y;
	
	if (m.size() == 0){
		// ���� ���� -> ��� �����ۿ� ������
		x = p[0];
		y = p[1];
		answer = y - x;
	}
	else if (p.size() == 0){
		x = m[m.size() - 2];
		y = m[m.size() - 1];
		answer = y - x;
	}
	else{
		for(int i = 0; i < m.size(); i++){
			
			int k = lower_bound(p.begin(), p.end(), -m[i]) - p.begin();
			if (m[i] + p[k] == 0){
				answer = 0;
				x = m[i];
				y = p[k];
				break;
			}
			sum = m[i] + p[k];
			if (answer > abs(sum)){
				answer = abs(sum);
				
				x = m[i];
				y = p[k];
			}
			 
			if (k != 0){
				// k - 1 ��쵵 �غ���
				sum = abs(m[i] + p[k - 1]);
				if (answer > sum){
					x = m[i];
					y = p[k - 1];
					answer = sum;
				}
			}
	
		}
	}
	
	// Ȥ�� �꼺����, ��Į�������� �Ѱ� �� 0�� ����� ���� �����Ƿ�
	
	if (m.size() > 1){
		sum = m[m.size() - 1] + m[m.size() - 2];

		if (answer > abs(sum)){
			answer = abs(sum);
			x = m[m.size() - 2];
			y = m[m.size() - 1];
		}
	}

	if (p.size() > 1){
		sum = p[p.size() - 1] + p[p.size() - 2];
		if (answer > abs(sum)){
			answer = abs(sum);
			cout << sum << endl;
			x = p[p.size() - 2];
			y = p[p.size() - 1];
		}
	}
	
	cout << x << " " << y;
	
	return 0;
	
}
