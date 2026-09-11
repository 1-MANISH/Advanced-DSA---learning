#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll* dp;

// House robber II
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/B

ll robHouse(int index,int n,vector<int>&house){

    if(index>n)return 0;

    if(dp[index]!=-1)
        return dp[index];

    // take it 
    ll ans1 = house[index]+robHouse(index+2,n,house);

    // not take it
    ll ans2 = robHouse(index+1,n,house);

    return dp[index]= max(ans1,ans2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>house(n+1);
    for(int  i = 1  ; i<=n ; i++)
        cin >> house[i];

    dp = new ll[n+1];
    for(int i = 0 ; i<= n ;i++)
        dp[i]=-1;

    cout << robHouse(1,n,house);

    return 0;
}
