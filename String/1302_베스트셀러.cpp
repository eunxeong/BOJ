#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
// 1302 베스트셀러

class Book{
public:
    string title;
    int cnt;
    Book(string title, int cnt){
        this->title = title;
        this->cnt = cnt;
    }
    bool operator <(Book &b){//이거 그만 까먹자!!
        if (this->cnt == b.cnt) return this->title < b.title;
        return this->cnt > b.cnt;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;  cin >> N;
    map<string, int> mp;
    vector<Book> V;

    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        mp[s]++;
    }

    map<string, int>::iterator iter;
    for(iter = mp.begin(); iter != mp.end(); iter++){
        V.push_back(Book(iter->first, iter->second));
    }

    sort(V.begin(), V.end());

    cout << V[0].title;

    return 0;

}