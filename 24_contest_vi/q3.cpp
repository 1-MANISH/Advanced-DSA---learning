#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll makeSingleDigit(ll N){
    if(N>=0 && N<=9){
        return N;
    }
    ll sum = 0;
    while(N>0){
        sum+=N%10;
        N/=10;
    }
    return makeSingleDigit(sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    cout << makeSingleDigit(N) << endl;


    return 0;
}