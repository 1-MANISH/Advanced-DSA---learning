#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    ll* dp;
public:
    Solution(int n){
        dp = new ll[n+1];
        for(int i = 0 ; i<= n ;i++)
            dp[i]=-1;
    }
    // House robber II
    // https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/B

    ll robHouse(int index,int n,vector<int>&house){

        if(index>=n)return 0;

        if(dp[index]!=-1)
            return dp[index];

        // take it 
        ll ans1 = house[index]+robHouse(index+2,n,house);

        // not take it
        ll ans2 = robHouse(index+1,n,house);

        return dp[index]= max(ans1,ans2);
    }
};

ll solve(vector<int>&arr){
    int n = arr.size();
    if(n==1)return arr[0];
    Solution* sol1 = new Solution(n);
    Solution* sol2 = new Solution(n);
    ll result1 = sol1->robHouse(0,n-1,arr);
    vector<int>arr2(n-1);
    for(int i=1 ; i<n ;i++)arr2[i-1]=arr[i];
    ll result2 = sol2->robHouse(0,n-1,arr2);

    return max(result1,result2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>house(n);
    for(int  i = 0  ; i<n ; i++)
        cin >> house[i];
    cout << solve(house);

    return 0;
}
