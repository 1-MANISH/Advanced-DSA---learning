
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int xr = 0;
    ll pref[2] = {0, 0};
    ll suff[2] = {0, 0};
    ll odd = 0;
};

Node mergeNodes(const Node &L, const Node &R) {
    Node res;

    res.xr = L.xr ^ R.xr;
    res.odd = L.odd + R.odd
            + L.suff[0] * R.pref[1]
            + L.suff[1] * R.pref[0];

    for (int p = 0; p < 2; ++p) {
        res.pref[p] += L.pref[p];
        res.pref[p ^ L.xr] += R.pref[p];

        res.suff[p] += R.suff[p];
        res.suff[p ^ R.xr] += L.suff[p];
    }

    return res;
}

struct SegmentTree {
    int size;
    vector<Node> tree;

    SegmentTree(const vector<int> &a) {
        size = 1;
        while (size < (int)a.size()) {
            size <<= 1;
        }

        tree.resize(2 * size);

        for (int i = 0; i < (int)a.size(); ++i) {
            tree[size + i] = makeNode(a[i]);
        }

        for (int i = size - 1; i >= 1; --i) {
            tree[i] = mergeNodes(tree[i << 1],
                                 tree[i << 1 | 1]);
        }
    }

    Node makeNode(int bit) {
        Node res;
        res.xr = bit;
        res.pref[bit] = 1;
        res.suff[bit] = 1;
        res.odd = bit;
        return res;
    }

    void update(int pos, int bit) {
        int p = size + pos;
        tree[p] = makeNode(bit);

        for (p >>= 1; p >= 1; p >>= 1) {
            tree[p] = mergeNodes(tree[p << 1],
                                 tree[p << 1 | 1]);
        }
    }

    ll getOdd() const {
        return tree[1].odd;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> edges(max(0, n - 1));
    ll sumTransitions = 0;

    for (int i = 0; i < n - 1; ++i) {
        edges[i] = (s[i] != s[i + 1]);

        if (edges[i]) {
            sumTransitions += 1LL * (i + 1) * (n - i - 1);
        }
    }

    SegmentTree seg(edges);

    auto answer = [&]() -> ll {
        return (sumTransitions + seg.getOdd()) / 2;
    };

    cout << answer();

    while (q--) {
        int pos;
        cin >> pos;
        --pos;

        s[pos] ^= 1;

        for (int e : {pos - 1, pos}) {
            if (e < 0 || e >= n - 1) {
                continue;
            }

            ll weight = 1LL * (e + 1) * (n - e - 1);

            if (edges[e]) {
                sumTransitions -= weight;
            } else {
                sumTransitions += weight;
            }

            edges[e] ^= 1;
            seg.update(e, edges[e]);
        }

        cout << ' ' << answer();
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// https://utho.com/?utm_source=google&utm_medium=cpc&utm_campaign=22982895529&utm_content=187927659987&utm_term=&utm_device=c&utm_network=&gad_source=2&gad_campaignid=22982895529&gclid=Cj0KCQjwt9jVBhDXARIsAFSP-6dviWnFLVHhnHp3OXcOTyu1n-DtDko0qwac1aHd9744mWuJsCOdq2MaAiU1EALw_wcB