#include <bits/stdc++.h>
using namespace std;

int main() {


    long long L, R;
    cin >> L >> R;

    long long ans = 0;

    // Check powers of two up to 2^60 (> 1e18)
    for (int k = 0; k <= 60; k++) {
        long long p = 1LL << k;
        if (p > R) break;
        if (p >= L) ans += p;
    }

    cout << ans << "\n";
    return 0;
}
