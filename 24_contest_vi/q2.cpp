#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int K;
    cin >> N >> K;

    for(int i = 0  ; i<K ; i++){
        N = N | (1LL<<i);
    }
    cout << N << endl;


    return 0;
}