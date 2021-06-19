#include <iostream>
#include <cstring>
#include <deque>

using namespace std;
// 2812 ũ�� �����

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;	cin >> N >> K;
	// 1 <= K < N <= 500,000
	
	// �ڿ��� Ȯ�� -> ������ ũ�� ������ ��
	// ������ ������ -> ����� �ȵ�
	// �̷��� �����Ѱ� �ƴϾ���.. �׳� ������ �տ������� ������������ ���;���
	// �׷��� �� ��� 
	
	string num;	cin >> num;
	deque<char> dq;
	
	for(int i = 0; i < num.length(); i++){
		
		while (K && !dq.empty() && (dq.back() < num[i])){
			dq.pop_back();
			K--;
		}
		
		dq.push_back(num[i]);
		
	}

	for(int i = 0; i < dq.size() - K; i++)	cout << dq[i];
	
	return 0;
	
}
