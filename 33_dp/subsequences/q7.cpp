#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/I
// I. Minimum Insertions to Make a String Palindrome

const int N = 1e3;
int dp[N][N];

int solve(int i,int j,string &s){

    // base case
    if(i>=j)return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0 ;
    // if current i and j pointer matched no need to insert
    if(s[i]==s[j]){
        ans = 0 + solve(i+1,j-1,s);
    }else{
        // no match b/w both i and j pointer -2 options

        // add at ith position
        int ans1 = 1+solve(i,j-1,s);

        // dd at jth position
        int ans2 = 1+solve(i+1,j,s);

        ans = min(ans1,ans2);
    }

    return dp[i][j] =  ans;
}

int minInsertToMakePaliindrome(string &s){
    memset(dp,-1,sizeof dp);
    return solve(0,s.size()-1,s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    string s;
    cin >> s;

    cout << minInsertToMakePaliindrome(s);
    

    return 0;
}
