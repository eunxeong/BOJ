#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
// 9046 복호화 10798 세로읽기 20154 이 구역의 승자는 누구야?

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
//	int arr[27];
//	int T;	cin >> T;
//	cin.ignore();
//	
//	while(T--){
//		
//		string s;
//		getline(cin, s);
//		
//		memset(arr, 0, sizeof(arr));
//		
//		for(int i = 0; i < s.length(); i++){
//			int idx = s[i];
//			if (idx >= 97 && idx <= 122){
//				idx -= 97;
//				arr[idx]++;
//			}
//		}
//		
//		int tmp = 0;
//		
//		for(int i = 0; i < 27; i++){
//			tmp = max(arr[i], tmp);
//		}
//		
//		stack<int> ans;
//		for(int i = 0; i < 27; i++){
//			if (arr[i] == tmp)	ans.push(i);
//		}
//		
//		if (ans.size() > 1)	cout << "?\n";
//		else{
//			char k = ans.top() + 97;
//			cout << k << "\n";
//		}
//		
//	}
//	
	
//	int N = 0;
//	vector<string> V;
//	
//	for(int i = 0; i < 5; i++){
//		string s;	cin >> s;
//		V.push_back(s);
//		N = max(N, (int)V[i].length());
//	}
//	
//	for(int i = 0; i < N; i++){
//		
//		for(int j = 0; j < 5; j++){
//			if (i >= V[j].length())	continue;
//			
//			cout << V[j][i];
//			
//		}
//		
//	}
	
	string s;	cin >> s;
	int arr[26] = { 3, 2, 1, 2, 3, 
					3, 3, 3, 1, 1, 
					3, 1, 3, 3, 1, 
					2, 2, 2, 1, 2, 
					1, 1, 2, 2, 2, 1 };
					
	vector<int> V;
	
	for(int i = 0; i < s.length(); i++){
		int idx = s[i];
		idx -= 65;
		V.push_back(arr[idx]);
	}
	
	vector<int> tmpV;
	
	while(1){
		tmpV.clear();
		
		int i = 0;
		while(i < V.size()){
			if (i + 1 == V.size()){
				tmpV.push_back(V[i]);
				break;
			}
			tmpV.push_back((V[i] + V[i + 1]) % 10);
			i += 2;
		}
		
		V = tmpV;
		
		if (V.size() == 1)	break;
	}
	
	if (V[0] % 2 == 0)	cout << "You're the winner?";
	else	cout << "I'm a winner!";
	
	return 0;
	
}
