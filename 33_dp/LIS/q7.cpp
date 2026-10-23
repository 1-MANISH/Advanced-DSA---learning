#include <bits/stdc++.h>
using namespace std;
#define v vector
//F. Longest Bitonic Subsequence
// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/F

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v<int>a(n);
    for(auto &x:a) cin >> x;


    // LIS ending at i
    v<int>left(n,1);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = i-1 ; j>=0 ; j--){
            if(a[j] < a[i]){
                left[i] = max(left[i],1+left[j]);
            }
        }
    }

    // LDS starting at i
    v<int>right(n,1);
    for(int i = n-1 ; i>=0 ; i--){
        for(int j = i+1; j < n ; j++){
            if(a[j]< a[i]){
                right[i] = max(right[i],1+right[j]);
            }
        }
    }

    // give every index chance to become peak element

    int ans= 0 ;

    for(int i = 0 ; i < n ; i++){
        if(left[i] > 1 and right[i] > 1) // need to drop
            ans = max(ans,left[i]+right[i]-1);
    }
    cout << ans;

    return 0;
}

