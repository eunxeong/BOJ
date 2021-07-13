#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 1969 DNA

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> V;
    int N, L;   cin >> N >> L;

    for(int i = 0; i < N; i++){
        string s;   cin >> s;
        V.push_back(s);
    }

    int a, t, g, c;

    string answer = "";
    int cnt = 0;

    for(int j = 0; j < L; j++){

        a = t = g = c = 0;

        for(int i = 0; i < N; i++){
            if (V[i][j] == 'A') a++;
            else if (V[i][j] == 'T')    t++;
            else if (V[i][j] == 'G')    g++;
            else    c++;
        }

        int cot = max(max(a, t), max(g, c));
        cnt += N - cot;
        if (a == cot){
            answer += "A";
            continue;
        }
        if (c == cot){
            answer += "C";
            continue;
        }
        if (g == cot){
            answer += "G";
            continue;
        }
        if (t == cot){
            answer += "T";
            continue;
        }

    }

    cout << answer << "\n" << cnt;
    return 0;

}