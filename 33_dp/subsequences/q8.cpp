#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/F
//  Distinct Subsequences - number of distinct subsequeuneces

const int N = 1e3;
ll dp[N][N];

ll solve(int i,int j,string &s,string &t){

    // base case
    if(j==t.size())return 1;

    if(i==s.size())return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    // not take it
    ll ans1 = solve(i+1,j,s,t);

    // take it - if possible to take s[i]==t[j]
    ll ans2 = 0;
    if(s[i]==t[j]){
        ans2 = solve(i+1,j+1,s,t);
    }

    return dp[i][j] =  ans1 + ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;

    cin >> s >> t;

    memset(dp,-1,sizeof dp);

    cout << solve(0,0,s,t);

    

    return 0;
}

