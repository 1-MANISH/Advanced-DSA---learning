#include <bits/stdc++.h>
using namespace std;

// parakeet ai
const int MOD  = 1e9 + 7;

// fib - recursive
int fib(int n){
    // base case
    if(n==0)return 0;
    if(n==1)return 1;

    int ans1 = fib(n-1);
    int ans2 = fib(n-2);

    return (ans1+ans2)%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // cout << fib(n);
    // recursion: n ----> 0
    // tabulation 0 ----> n

    vector<int>dp(n+1,0);
    for(int i = 0 ; i <= n ; i++){

        int &ans = dp[i];

        if(i==0){
            ans=0;
            continue;
        }
        if(i==1){
            ans=1;
            continue;
        }

        int ans1 = dp[i-1];
        int ans2 = dp[i-2];

        ans =  (ans1+ans2)%MOD;
    }

    cout << dp[n] << endl;

    return 0;
}



