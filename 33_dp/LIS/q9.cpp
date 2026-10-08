#include <bits/stdc++.h>
using namespace std;
#define v vector


// LIS- using candidate / wala method
// Reconsturuct the subquence

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v<int>a(n);
    for(auto &x:a) cin >> x;

    vector<int>candidates(n+1,INT_MAX); // best candidate for each length
    vector<int>dp(n+1,1);
    candidates[0]=INT_MIN;


    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        // find prev -  element in candidates[0,n] where element greater >= A[i]
        auto it = lower_bound(candidates.begin(),candidates.end(),a[i]);
        *it = a[i] ;// place length i par correct candidate /element
        // ans = max(ans,(int)(it - candidates.begin()));
        dp[i] = it - candidates.begin();// elements less than a[i] in a[0....i-1]
    }
    
    
    int idx = max_element(dp.begin(),dp.end())-dp.begin();
    int len = dp[idx];

    cout << len << endl;

    vector<int>result;

    while(len>0){
        if(dp[idx]==len){ // till now max length of LIS
            result.push_back(a[idx]);
            len--;
        }
        idx--;
    }

    for(auto &ele:dp)cout << ele << " ";
        cout << endl;

    reverse(result.begin(),result.end());

    for(auto &ele:result)cout << ele << " ";
    return 0;
}

