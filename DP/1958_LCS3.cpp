#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
// 1958 LCS 3
/*
	처음 떠올렸던 s1, s2의 공통부분 구해서 s3이랑 해주는건
	반례 존재해서 3차원 배열로 품 
*/ 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();
	
	int d[102][102][102];
	
	for(int i = 0; i <= len1; i++){
		for(int j = 0; j <= len2; j++){
			for(int k = 0; k <= len3; k++){
				d[i][j][k] = 0;
			}
		}
	}
	
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			for(int k = 1; k <= len3; k++){
				d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]){
					d[i][j][k] = max(d[i][j][k], d[i - 1][j - 1][k - 1] + 1);
				}
				
			}
		}
	}
	
	cout << d[len1][len2][len3];
	
	return 0;
}
