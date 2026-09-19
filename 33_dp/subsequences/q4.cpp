#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/D
// D Edit Distance

int solve(int i,int j,string &s,string &t){

    // base case

    if(i==s.size()){
        return t.size()-j; // let suppose s string complted and 2 char rem in t
    }

    if(j==t.size()){
        return s.size()-i; // let suppose t string complted and 2 char rem in s
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;

    // if current character matched on both pointer
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
    }else{

        // replace a character
        int ans1 = 1 + solve(i+1,j+1,s,t);

        /// insert a character
        // s[....] t = [...]
        // insert in s  or remove in t
        int ans2 = 1 + solve(i,j+1,s,t);

        // insert in t or remove in s
        int ans3 = 1 + solve(i+1,j,s,t);

        ans = min(ans1,min(ans2,ans3));
    }
    return dp[i][j] = ans;
}

int editDistance(string &s,string &t){
    memset(dp,-1,sizeof dp);
    return solve(0,0,s,t);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;

    cin >> s>> t;

    cout << editDistance(s,t);

    
    return 0;
}

