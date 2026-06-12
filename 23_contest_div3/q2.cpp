#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        bool ok = true;

        for (int r = 0; r < k; r++) {
            int parity = 0;

            for (int i = r; i < n; i += k) {
                parity ^= (s[i] - '0');
            }

            if (parity) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}