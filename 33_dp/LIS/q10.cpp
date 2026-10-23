
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull  unsigned long long
#define v vector

// #I. Increasing Triplet Subsequence
// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/I

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   

    int n;
    cin >> n;
    v<int>a(n);
    for(auto &x:a) cin >> x;

    vector<int>dp(n);    

    v<ll>candidates(n+1,LLONG_MAX);
    candidates[0] = LLONG_MIN;

    for(int i = 0 ; i < n  ; i++){
        // best canidate at number i till now including this current
        // lower_bound >= x
        auto it = lower_bound(candidates.begin(),candidates.end(),a[i]);
        *it = a[i]; // placing right min candiate at length of lIS  = i
        dp[i] = it-candidates.begin();
    }

    int len_lis = *max_element(dp.begin(),dp.end());

    cout << (len_lis >= 3 ? "YES":"NO");

    return 0;
}