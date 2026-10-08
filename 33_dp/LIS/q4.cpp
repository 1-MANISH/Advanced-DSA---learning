#include <bits/stdc++.h>
using namespace std;

// C. Longest Decreasing Subsequence
// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/C

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);
    for(auto &x:arr)
        cin >> x;


    vector<int>dp(n,1);// as single element make dec sub-seq

    for(int i = 0 ; i< n ; i++){
        for(int j = i-1 ; j >=0 ; j--){
            if(arr[j] > arr[i]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }

    cout << *max_element(dp.begin(),dp.end());
    return 0;
}

