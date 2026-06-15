#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countTrailingZeros(ll N){

    int count = 0;
    for(int i = 0 ; i<=63 ; i++){
        if( N & (1LL<<i))break;
        else count++;
    }
    return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    cout << countTrailingZeros(N);

    return 0;
}