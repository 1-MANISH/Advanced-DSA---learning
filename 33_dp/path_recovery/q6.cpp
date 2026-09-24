#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/F
//F. Printing LCS
const int N = 1e3;
int dp[N][N];

string result = "";

int solve(int i,int j,string &s,string &t){

    // base case
    if(i==s.size() or j==t.size()){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0 ;
    // both current char ares equal
    if(s[i]==t[j]){
        ans = 1 + solve(i+1,j+1,s,t);
    }else{
        // take it i wala - ignoring j wala
        int ans1 = solve(i,j+1,s,t);

        // take it j wala - ignoring i wala
        int ans2 = solve(i+1,j,s,t);

        ans = max(ans1,ans2);
    }

    return dp[i][j] = ans;
}

void recover(int i,int j,string &s,string &t){

    // base case
    if(i==s.size() or j==t.size()){
        return;
    }

    int ans = 0 ;
    // both current char ares equal
    if(s[i]==t[j]){
        ans = 1 + solve(i+1,j+1,s,t);
        // taking this char - lets reterive into path 
        result+=s[i];
        recover(i+1,j+1,s,t);
    }else{
        // take it i wala - ignoring j wala
        int ans1 = solve(i,j+1,s,t);

        // take it j wala - ignoring i wala
        int ans2 = solve(i+1,j,s,t);

        ans = max(ans1,ans2);

        if(ans==ans1){
            // means consider for i wala
            recover(i,j+1,s,t);
        }else{
            recover(i+1,j,s,t);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;

    memset(dp,-1,sizeof dp);
    solve(0,0,s,t);
    recover(0,0,s,t);

    cout << result;

    

    return 0;
}

