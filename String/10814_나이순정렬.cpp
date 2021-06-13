#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
// 10814 나이순 정렬

struct MEMBER{
	int age, date;
	string name;
};

struct cmp{
	bool operator()(MEMBER m1, MEMBER m2){
		if (m1.age == m2.age){
			return m1.date > m2.date;
		}
		return m1.age > m2.age;
	}
};

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<MEMBER, vector<MEMBER>, cmp> pq;
	
	int N;	cin >> N;
	
	MEMBER m;
	int x;
	string str;
	
	for(int i = 1; i <= N; i++){
		cin >> x >> str;
		m.age = x;
		m.date = i;
		m.name = str;
		pq.push(m);
	}
	
	while(!pq.empty()){
		m = pq.top();
		pq.pop();
		
		cout << m.age << " " << m.name << "\n";
		
	}
	
	return 0;
	
}
