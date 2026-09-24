#include <bits/stdc++.h>
using namespace std;
#define ll long long

// B. Frog Jump I (Print Path)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/B

const int N = 1e5;
ll dp[N];

vector<int>path;

ll solve(int index,int n,vector<int>&stairs){

    // base case
    if(index>=n)return INT_MAX;

    if(index==n-1){
        return 0;
    }

    if(dp[index]!=-1)return dp[index];

    // take one step
    ll ans1 =  abs(stairs[index]- stairs[index+1]) + solve(index+1,n,stairs);

    // take 2 steps
    ll ans2 = INT_MAX;
    if(index+2<=n-1);
        ans2 = abs(stairs[index]-stairs[index+2]) + solve(index+2,n,stairs);

    ll ans = min(ans1,ans2);

    return dp[index] =  ans;
}


void recover(int index,int n,vector<int>&stairs){

    // base case
    if(index>=n)return;

    if(index==n-1){
        path.push_back(n-1);
        return ;
    }


    // take one step
    ll ans1 =  abs(stairs[index]- stairs[index+1]) + solve(index+1,n,stairs);

    // take 2 steps
    ll ans2 = INT_MAX;
    if(index+2<=n-1);
        ans2 = abs(stairs[index]-stairs[index+2]) + solve(index+2,n,stairs);

    ll ans = min(ans1,ans2);

    if(ans==ans1){
        path.push_back(index);
        recover(index+1,n,stairs);
    }else{
        path.push_back(index);
        recover(index+2,n,stairs);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>stairs(n);
    for(int i = 0 ; i  < n ; i++)
        cin >> stairs[i];

    memset(dp,-1,sizeof dp);

    cout << solve(0,n,stairs) << endl;

    recover(0,n,stairs);

    for(auto &ele:path)cout << ele << " ";

    return 0;
}

