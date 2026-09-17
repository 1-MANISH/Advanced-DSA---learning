#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4;
vector<vector<int>>dp(N,vector<int>(N,-1));

int f(ll index,ll current,ll &n){


    if(current>=n){
        return 0;
    }

    if(dp[index][current]!=-1){
        return dp[index][current];
    }

    return dp[index][current]= 1+f(index+1,current+index-1,n);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    cout << f(1,0,n);


    return 0;
}

