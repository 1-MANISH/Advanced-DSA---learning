#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int n = S.size();
    int m = T.size();
    int i = 0, j = 0;

    bool first = true;

    while (i < n || j < m) {

        if (i < n) {
            if (!first) cout << "-";
            cout << S[i++];
            first = false;
        }

        if (j < m) {
            cout << "-";
            cout << T[j++];
            first = false;
        }
    }

    return 0;
}