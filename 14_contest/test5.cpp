#include<bits/stdc++.h>
using namespace std;



int main(){

	int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<long long, long long> freq;
    long long count = 0;

    if (k == 0) {
        long long seen = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count += seen; // all previous elements form valid pair
            }
            seen++;
        }
    } else {
        for (int i = 0; i < n; i++) {
            long long x = arr[i];

            if (x % k == 0) {
                long long target = x / k;
                if (freq.count(target)) {
                    count += freq[target];
                }
            }

            freq[x]++;
        }
    }

    cout << count << "\n";




	
	return  0;
}