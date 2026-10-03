#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/3403
// longtest common subsequence

const int N = 1e3;
const int M = 1e3;

int dp[N][M];

vector<int>result;

int solve(int i,int j,vector<int>&a,vector<int>&b){

    // base cases
    if(i==a.size() or j==b.size()){
        return 0 ;
    }

    if(dp[i][j]!=-1) return dp[i][j];
    //both current pointer matches
    int ans = 0 ;
    if(a[i]==b[j]){
        ans  =  1 + solve(i+1,j+1,a,b);
    }else{
        // consider ith 
        int ans1 = solve(i,j+1,a,b);

        // consider jth
        int ans2 = solve(i+1,j,a,b);

        ans = max(ans1,ans2);
    }

    return dp[i][j] =  ans;
}

void recover(int i,int j,vector<int>&a,vector<int>&b){

    // base cases
    if(i==a.size() or j==b.size()){
        return ;
    }

    //both current pointer matches
    int ans = 0 ;
    if(a[i]==b[j]){
        ans  =  1 + solve(i+1,j+1,a,b);
        result.push_back(a[i]);
        recover(i+1,j+1,a,b);
    }else{
        // consider ith 
        int ans1 = solve(i,j+1,a,b);

        // consider jth
        int ans2 = solve(i+1,j,a,b);

        ans = max(ans1,ans2);

        if(ans==ans1){
            recover(i,j+1,a,b);
        }else{
            recover(i+1,j,a,b);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int>a(n),b(m);
    for(int i = 0 ; i < n  ; i++)
        cin >> a[i];
    for(int j = 0 ;  j < m; j++)
        cin >> b[j];

    memset(dp,-1,sizeof dp);
    cout << solve(0,0,a,b) << endl;
    recover(0,0,a,b);
    for(auto &ele:result)
        cout << ele << " ";
    
    return 0;
}
