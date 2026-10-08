#include <bits/stdc++.h>
using namespace std;

//  Minimum Deletions to Make Array Increasing
// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/D

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    int n;
    cin >> n;
    vector<int>arr(n);
    for(auto &x:arr) cin >> x;

    vector<int>dp(n,1);
    for(int i = 0 ; i < n  ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }    

    int lis  = *max_element(dp.begin(),dp.end());
    cout << n-lis << endl;
    return 0;
}

