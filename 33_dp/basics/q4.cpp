#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long dp[N];

// https://blog.logrocket.com/guide-to-fully-understanding-redis/


// cost to climb stairs
// trying to reach n+1
long long minCost(int step , int n, vector<int>&cost){

	if(step>=n)return 0;

    if(dp[step]!=-1){
        return dp[step];
    }

    long long ans1 = 0LL+cost[step+1]+minCost(step+1,n,cost);

    long long ans2 = INT_MAX ;
    if(step+2<=n){
        ans2 = 0LL+cost[step+2]+minCost(step+2,n,cost);
    }
    return dp[step] = min(ans1,ans2);
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>cost(n+2,0);
    for(int i = 1 ; i<=n ;i++){
        cin >> cost[i];
    } 
    for(int i = 0 ; i <= n+1 ; i++){
    	dp[i] = -1;
    }
    if(n==1){
        cout << cost[1] << endl;// edge case 
        return 0 ;
    }
    cout << minCost(0,n+1,cost) << endl;


    return 0;
}