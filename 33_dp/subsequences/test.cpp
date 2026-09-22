#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        vector<vector<int>> g(n + 1);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n + 1, 0);
        vector<int> order;
        order.reserve(n);

        parent[1] = -1;
        order.push_back(1);

        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];

            for (int v : g[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<ll> r(n + 1);
        vector<ll> d(n + 1);
        vector<ll> sumR(n + 1, 0);
        vector<ll> gcdD(n + 1, 0);

        ll answer = 0;


        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            bool leaf = true;
            for (int v : g[u]) {
                if (parent[v] == u) {
                    leaf = false;
                    break;
                }
            }

            if (leaf) {
                r[u] = a[u];
                d[u] = 0;
            } else {

                d[u] = __gcd(b[u], sumR[u]);
                d[u] = __gcd(d[u], gcdD[u]);

                r[u] = a[u] % d[u];
            }


            ll best;

            if (d[u] == 0) {
                best = a[u];
            } else {
                best = b[u] - d[u] + r[u];
            }

            answer += best;

            if (parent[u] != -1) {
                int p = parent[u];

                sumR[p] += r[u];
                gcdD[p] = __gcd(gcdD[p], d[u]);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}