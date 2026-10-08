#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/B
//  Print the Longest Increasing Subsequence

const int N = 2000;
int dp[N][N+1];
vector<int>result;

int solve(int index,int prevIndex,vector<int>&arr){

    // base cases
    if(index==arr.size())
        return 0 ;

    if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];
    // not take it
    int ans1 = solve(index+1,prevIndex,arr);

    // take it  -  if we can
    int ans2 = 0 ;
    if(prevIndex == arr.size() or (arr[prevIndex] < arr[index])){
        ans2 = 1 + solve(index+1,index,arr);
    }

    return dp[index][prevIndex] = max(ans1,ans2);
}

void recover(int index,int prevIndex,vector<int>&arr){

    // base cases
    if(index==arr.size())
        return ;

    
    // not take it
    int ans1 = solve(index+1,prevIndex,arr);

    // take it  -  if we can
    int ans2 = 0 ;
    if(prevIndex == arr.size() or (arr[prevIndex] < arr[index])){
        ans2 = 1 + solve(index+1,index,arr);
    }

    int ans = max(ans1,ans2);

    if(ans==ans1){
        recover(index+1,prevIndex,arr);
    }else{
        if(prevIndex == arr.size() or (arr[prevIndex] < arr[index])){
            result.push_back(arr[index]);
            recover(index+1,index,arr);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n  ; i++)
        cin >> arr[i];

    memset(dp,-1,sizeof dp);

    cout << solve(0,n,arr) << endl;

    recover(0,n,arr);

    for(auto &ele:result) cout << ele << " ";

    return 0;
}

