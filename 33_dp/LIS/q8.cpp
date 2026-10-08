#include <bits/stdc++.h>
using namespace std;
#define v vector


// LIS- using candidate / wala method
// Only length we get  - LIS is in-correct sometimes

// lower bound -   means - element greater than equal to that element
    // element not exist(smaller) - A[0]
    // element is greater than array element - A[n] - A.end()

// upperbound - means element greater than to that element
    //// element not exist(smaller) -A[0]
    // element is greater than array element - A[n] - A.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v<int>a(n);
    for(auto &x:a) cin >> x;

    vector<int>candidates(n+1,INT_MAX); // best candidate for each length

    candidates[0]=INT_MIN;

    // for(int i = 0 ; i < n ; i++){
    //     // find prev -  element in candidates[0,n] where element greater >= A[i]
    //     auto it = lower_bound(candidates.begin(),candidates.end(),a[i]);
    //     *it = a[i] ;// place length i par correct candidate /element
    // }
    // int ans = 0 ;
    // for(int i = 1  ; i <=n ; i++){
    //     if(candidates[i]==INT_MAX)break;
    //     ans++;
    // }
    // cout << ans;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        // find prev -  element in candidates[0,n] where element greater >= A[i]
        auto it = lower_bound(candidates.begin(),candidates.end(),a[i]);
        *it = a[i] ;// place length i par correct candidate /element
        ans = max(ans,(int)(it - candidates.begin()));
    }
    cout << ans;

    return 0;
}

