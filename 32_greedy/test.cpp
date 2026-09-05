#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int &x : arr)
            cin >> x;

        int start = -1;
        int best_left = -1, best_right = -1;
        int best_len = 0;

        for (int i = 0; i < n; ++i) {

            if (arr[i] == 0)
                continue;

            if (start == -1)
                start = i;

            // Current interval [start, i]
            int len = i - start + 1;

            if (len > best_len) {
                best_len = len;
                best_left = start;
                best_right = i;
            }

            if (arr[i] == 1) {
                start = i;
            }
        }

        // Replace all -1 to 0,
        for (int i = 0; i < n; ++i) {
            if (arr[i] == -1)arr[i] = 0;
        }

        if (best_left != -1) {
            arr[best_left] = 1;
            arr[best_right] = 1;
        }

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}