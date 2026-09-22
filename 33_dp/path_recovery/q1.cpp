#include <bits/stdc++.h>
using namespace std;

// A. Is Subsequence
// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/A

bool isSubSequence(string &s,string &t){
    int n = t.size() ,   m =   s.size();
    int i = 0 ,  j =0  ;
    while( i < n && j < m){
        if(t[i]==s[j]){
            j++;
        }
        i++;
    }
    return j==m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s  >> t;

    cout << (isSubSequence(s,t)?"YES\n":"NO\n");

    return 0;
}

