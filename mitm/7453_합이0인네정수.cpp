#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 7453 합이 0인 네 정수

int N;
long long arr[4][4001];
long long int answer = 0;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
	}
	
	vector<long long> right;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			right.push_back(arr[2][i] + arr[3][j]);
		}
	}
	
	sort(right.begin(), right.end());
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			
			long long half = arr[0][i] + arr[1][j];
			
			int l = lower_bound(right.begin(), right.end(), -half) - right.begin();
			int u = upper_bound(right.begin(), right.end(), -half) - right.begin();
			
			if (right[l] == -half){
				answer += u - l;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}


/*
시간 절약되는 좋은 코드라 복붙해옴
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> a,b;
    cin>>n;
    int arr[n][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++) //최대 4000*4000 16000000 천육백만*2
    {
        for(int j=0;j<n;j++)
        {
            a.push_back(arr[i][0]+arr[j][1]);
            b.push_back(arr[i][2]+arr[j][3]);
        }
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    long long res=0; 
    
    for(int i=0;i<a.size();i++)
    {
        res+=upper_bound(b.begin(),b.end(),-a[i])-lower_bound(b.begin(),b.end(),-a[i]);
    }
    cout<<res;
    return 0;
}

*/
