#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool compare(string &a,string &b){
    return a+b<b+a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string>arr(n);
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin >> ele;
        arr[i]=to_string(ele);
    }
    sort(arr.begin(),arr.end(),compare);
    for(auto &ele:arr)cout << ele;

    

    return 0;
}