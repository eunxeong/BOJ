#include <iostream>
#include <algorithm>
#include <algorithm>

using namespace std;
// 9576 책 나눠주기

class Book{
public:
	int a;
	int b;
	Book(int a, int b){
		this->a = a;
		this->b = b;
	}
};

bool cmp(Book b1, Book b2){
	if (b1.b == b2.b)	return b1.a < b2.a;
	return b1.b < b2.b;
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;	cin >> T;
	while(T--){
		vector<Book> list;
		int N, M;	cin >> N >> M;
		for(int i = 0; i < M; i++){
			int a, b;	cin >> a >> b;
			list.push_back(Book(a, b));
		}
		
		bool d[1001] = { false, };
		sort(list.begin(), list.end(), cmp);
		
		int Answer = 0;
		
		for(auto k : list){
			
			bool tmp = false;
			for(int i = k.a; i <= k.b; i++){
				if (!d[i]){//false면 들어갈수 있는거니까 
					d[i] = true;
					tmp = true;
					break;
				}
			}
			
			if (tmp)	Answer++;
			
		}
	
		cout << Answer << "\n";
	
	}
	
	return 0;
	
}
