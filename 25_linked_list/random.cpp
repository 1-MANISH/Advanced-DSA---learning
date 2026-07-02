#include <bits/stdc++.h>
using namespace std;

bool good(long long x) {
    bool vis[10] = {};
    int cnt = 0;
    if (x == 0) return true;
    while (x) {
        int d = x % 10;
        if (!vis[d]) {
            vis[d] = true;
            cnt++;
            if (cnt > 2) return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> all;

    // Numbers with one repeated digit
    for (int len = 1; len <= 10; len++) {
        for (char d = '1'; d <= '9'; d++) {
            string s(len, d);
            long long v = stoll(s);
            if (v >= 2 && v <= 1000000000LL)
                all.push_back(v);
        }
    }

    // Numbers with at most two digits
    for (int len = 1; len <= 10; len++) {
        for (char a = '0'; a <= '9'; a++) {
            for (char b = a + 1; b <= '9'; b++) {
                int masks = 1 << len;
                for (int mask = 0; mask < masks; mask++) {
                    string s;
                    for (int i = 0; i < len; i++) {
                        s += ((mask >> i) & 1) ? b : a;
                    }
                    if (s[0] == '0') continue;
                    long long v = stoll(s);
                    if (v >= 2 && v <= 1000000000LL)
                        all.push_back(v);
                }
            }
        }
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int T;
    cin >> T;

    while (T--) {
        long long x;
        cin >> x;

        for (long long y : all) {
            if (good(x * y)) {
                cout << y << '\n';
                break;
            }
        }
    }

    return 0;
}