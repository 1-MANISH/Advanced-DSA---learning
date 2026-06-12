#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<long long, long long>& p) const {
        return p.first * 1000003ULL ^ p.second;
    }
};

long long X;
unordered_map<pair<long long, long long>, long long, PairHash> memo;

long long solve(long long a, long long b) {
    if (a > b) swap(a, b);
    if (a == b) return 0;

    pair<long long, long long> state = {a, b};
    auto it = memo.find(state);
    if (it != memo.end()) return it->second;

    long long ans = b - a; // make them equal using only +1

    ans = min(ans, 1 + solve(a / X, b));
    ans = min(ans, 1 + solve(a, b / X));

    return memo[state] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b >> X;

        memo.clear();
        cout << solve(a, b) << '\n';
    }

    return 0;
}