#include <bits/stdc++.h>
using namespace std;

//  Longest Common Subsequence
/*

DIRECTION:
    REC :
        i = 0  to  n 
        j = 0  to  m
    TAB :
        i = n  to  0
        j = m  to  0
*/

int solve(int i,int j,string &s,string &t){

    // base cases
    if(i==s.size() or j == t.size()){
        return 0;
    }

    // both current pointer char matches
    int ans = 0  ;
    if(s[i]==t[j]){
        ans = 1 + solve(i+1,j+1,s,t);
    }else{
        // either consider ith wala part
        int ans1 = solve(i,j+1,s,t);
        // either consider jth wala part
        int ans2 = solve(i+1,j,s,t);

        ans = max(ans1,ans2);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;

    // cout << solve(0,0,s,t);
    int n = s.size() , m = t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1));

    for(int i = n ; i >=0 ; i--){
        for(int j = m ; j >=0 ; j--){

            int &answer = dp[i][j];

            if(i==n or j == m){
                answer = 0;
                continue;
            }

            // both current pointer char matches
            int ans = 0  ;
            if(s[i]==t[j]){
                ans = 1 + dp[i+1][j+1];
            }else{
                // either consider ith wala part
                int ans1 = dp[i][j+1];
                // either consider jth wala part
                int ans2 = dp[i+1][j];

                ans = max(ans1,ans2);
            }
            answer = ans;
        }
    }

    cout << dp[0][0];

    return 0;
}



