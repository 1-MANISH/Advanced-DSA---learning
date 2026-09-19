#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/E
// E. Minimum Steps to Make Two Strings Equal

const int N = 1e3;
int dp[N][N];

int solve(int i,int j,string &s,string &t){


    // base case
    if(i==s.size()){
        return t.size()-j;
    }
    if(j==t.size()){
        return s.size()-i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }


    int ans = 0;

    // current pointer matches
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
    }else{
        // delete a character

        // delete in s
        int ans1 = 1 + solve(i+1,j,s,t);

        // delete in t
        int ans2 = 1 + solve(i,j+1,s,t);

        ans = min(ans1,ans2);
    }

    return dp[i][j] = ans;
}

int makeStringEqual(string &s,string &t){
    memset(dp,-1,sizeof dp);
    return solve(0,0,s,t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;

    cout << makeStringEqual(s,t);

    

    return 0;
}

