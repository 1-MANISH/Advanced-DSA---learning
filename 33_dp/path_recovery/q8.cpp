#include <bits/stdc++.h>
using namespace std;

// H. Longest Palindromic Subsequence (Print LPS)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/H
const  int N =  1e3;

int dp[N][N];

string front = "";
string back = "";
int solve(int i,int j ,string &s){

    // base case
    if(i == j)return 1;
    if(i > j)return 0;


    if(dp[i][j]!=-1) return dp[i][j];

    // if character match
    int ans = 0 ;
    if(s[i]==s[j]){
        ans = 2 + solve(i+1,j-1,s);
    }else{

        // consider j index char 
        int ans1 = solve(i+1,j,s);

        // consider i index char
        int ans2 = solve(i,j-1,s);

        ans =  max(ans1,ans2);
    }

    return  dp[i][j] = ans;
}

void recover(int i,int j ,string &s){

    // base case
    if(i > j)return ;

    if(i == j){
        back+=s[i];
        return;
    }

    // if character match
    int ans = 0 ;
    if(s[i]==s[j]){
        ans = 2 + solve(i+1,j-1,s);
        front+=s[i];
        back+=s[j];
        recover(i+1,j-1,s);
    }else{

        // consider j index char 
        int ans1 = solve(i+1,j,s);

        // consider i index char
        int ans2 = solve(i,j-1,s);

        ans  =  max(ans1,ans2);

        if(ans==ans1){
            recover(i+1,j,s);
        }else{
            recover(i,j-1,s);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    string s;
    cin >> s;
    memset(dp,-1,sizeof dp);
    cout << solve(0,s.size()-1,s) << endl;
    recover(0,s.size()-1,s);

    reverse(back.begin(),back.end());
    cout << front+back << endl;

    return 0;
}

