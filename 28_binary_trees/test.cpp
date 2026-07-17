#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        int64 c;
        cin >> n >> c;

        vector<int64> a(n + 2, 0);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int64> dp(n + 3, 0);

        for (int i = n; i >= 1; i--) {
            dp[i] = a[i] - c + dp[i + 1];

            if (i < n) {
                dp[i] = max(dp[i],
                            max(a[i], a[i + 1]) - c + dp[i + 2]);
            }
        }

        cout << dp[1] << '\n';
    }

    return 0;
}