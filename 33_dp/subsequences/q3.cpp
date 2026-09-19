#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/C
//LCS of Three Strings
const int N = 1e2;
int dp[N][N][N];


int solve(int i ,int j , int k , string &s1,string &s2,string &s3){

    // base case

    if(i==s1.size() or j==s2.size() or k==s3.size()){
        return  0;
    }

    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }

    int ans = 0 ;
    // if current index of all matched
    if(s1[i]==s2[j] and s2[j]==s3[k]){
        ans = 1 + solve(i+1,j+1,k+1,s1,s2,s3);
    }else{
        // let move i forward
        int ans1 = solve(i+1,j,k,s1,s2,s3);

        // let move j forward
        int ans2 = solve(i,j+1,k,s1,s2,s3);

        // let move k forward
        int ans3 = solve(i,j,k+1,s1,s2,s3);

        ans = max(ans1,max(ans2,ans3));
    }

    return dp[i][j][k]= ans;
}

int longestCommonSubsequence(string &s1,string &s2 ,string &s3){
    memset(dp,-1,sizeof dp);
    return  solve(0,0,0,s1,s2,s3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    cout << longestCommonSubsequence(s1,s2,s3);
    

    return 0;
}

