#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
// 7785 회사에 있는 사람

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	cin >> N;
//	1000001
	string arr[10000];
	for(int i = 0; i < N; i++)	cin >> arr[i];
	
	sort(arr, arr + N);
	int idx = 0;
	priority_queue<string> pq;
	
	string str = arr[idx];
	if (str.find("enter"))	cout << "enter";
	if (arr[idx + 2].find("leave"))	cout << "leave";
	while(idx > N){
		string str = arr[idx];
		
		
		
	}

}

//using namespace std;
//// 1764 듣보잡 
//
//int main(){
//
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);	cout.tie(0);
//	
//	int N, M;	cin >> N >> M;
//	string arr[1000001];
//	
//	for(int i = 0; i < N + M; i++){
//		cin >> arr[i];
//	}
//	
//	sort(arr, arr + N + M);
//	
//	int idx = 0;
//	int Answer = 0;
//	string ans[500001];
//	while(idx < N + M){
//		if (arr[idx] == arr[idx + 1]){
//			ans[Answer] = arr[idx];
//			idx = idx + 2;
//			Answer++;
//		}
//		else{
//			idx = idx + 1;
//		}
//	}
//	
//	cout << Answer << "\n";
//	for(int i = 0; i < Answer; i++)	cout << ans[i] << "\n";
//	
//	return 0;
//
//}
