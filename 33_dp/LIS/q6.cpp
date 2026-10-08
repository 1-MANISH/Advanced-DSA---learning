#include <bits/stdc++.h>
using namespace std;
#define int long long
#define v vector

// E. Number of Longest Increasing Subsequences
//https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/E
// count of LIS

const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin >>n;
    v<int>arr(n);
    for(auto &x:arr) cin >> x;

    v<int>dp(n,1);
    v<int>cnt(n,0);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }   

    for(int i = 0 ; i < n ; i++)
    {
        if(dp[i]==1){
            cnt[i]=1;
            continue;
        }
        for(int j = i-1 ; j >=0 ;j--){
           if(arr[j] < arr[i] and dp[j] == dp[i]-1 ){
                cnt[i] = (cnt[i]+cnt[j])%MOD;
           } 
        }
    }   


    int lis_len = *max_element(dp.begin(),dp.end());
    int ans = 0 ;
    for(int i = 0 ; i< n ; i++){
        if(dp[i]==lis_len){
            ans = (ans+cnt[i])%MOD;
        }
    }

    cout << ans;

    return 0;
}

