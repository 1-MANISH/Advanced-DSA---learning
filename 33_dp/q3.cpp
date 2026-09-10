#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = 1e9+7;

int dp[N+1];


// stair case

int numberOfWays(int n){
	if(n<=1)return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = (numberOfWays(n-1)+numberOfWays(n-2))%M;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0 ; i < n+1 ; i++){
    	dp[i]=-1;
    }

    cout << numberOfWays(n);

    return 0;
}