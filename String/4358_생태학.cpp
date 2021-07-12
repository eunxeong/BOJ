#include <iostream>
#include <math.h>
#include <string>
#include <map>

using namespace std;
// 4358 생태학

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mp;

    int n = -1;

    while(1){

        string s;
        n++;
        getline(cin, s);

        if (cin.eof())  break;

        mp[s]++;

    }

    map<string, int>::iterator iter;

    for(iter = mp.begin(); iter != mp.end(); iter++){
        
        string tmp = iter->first;
		double k = iter->second;
        k = k * 100 / n;
        k *= pow(10, 3);
        round(k);
        k /= pow(10, 3);

        cout << tmp << " ";
        cout << fixed;
        cout.precision(4);
        cout << k << "\n";
//		printf(" %.4f\n", k);

    }
    
    return 0;

}
