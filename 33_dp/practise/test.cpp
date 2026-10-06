#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3;
ll dp[N][N];

int x,y,z;
string A,B;

ll solve(int i,int j){
    
    // base cases
    if(i==A.size()){
        // if in B string chars remaining means  -  need to add char into A
        return 1LL*(B.size()-j)*x;
    }
    
    if(j==B.size()){
        // means need to delete char remaining in A 
        return 1LL*(A.size()-i)*y;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    // both current char equal no-  operation
    ll ans = 0;
    if(A[i]==B[j]){
        ans = solve(i+1,j+1);
    }else{
        // insert char in A
        ll ans1 = x + solve(i,j+1);
        
        // delete a char in A
        ll ans2 = y + solve(i+1,j);
        
        // replace with another char
        ll ans3 = z + solve(i+1,j+1);
        
        ans = min(ans1,min(ans2,ans3));
    }
    return dp[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    cin >> x >> y >> z;
    cin >> A >> B;
    memset(dp,-1,sizeof dp);
    cout << solve(0,0);
    
    return 0;
}
