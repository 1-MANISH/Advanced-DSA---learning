
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull  unsigned long long
#define v vector

struct Envelope{
    int w,h;
};

// #https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/
// J. Russian Doll Envelopes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v<Envelope>a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].w >> a[i].h;

    sort(a.begin(),a.end(),[](const Envelope &a,const Envelope &b){
        if(a.w==b.w)return a.h > b.h;
        return a.w < b.w;
    });

    v<int>dp(n,1);
    v<int>candidates(n+1,INT_MAX);
    candidates[0] = INT_MIN;
    

    for(int i = 0 ; i < n ; i++){
       auto it = lower_bound(candidates.begin(),candidates.end(),a[i].h,[](const int &element,const int &value ){
            return element < value ;
       });
       *it = a[i].h;
       dp[i] = it-candidates.begin();
    }

    cout << *max_element(dp.begin(),dp.end());

    return 0;
}


/*

ETYSY|WHOP



Get comfortable
with your own company
. not every beautiful
moment needs to be shared
with someone.
*/