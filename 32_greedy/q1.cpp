#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/assign-cookies/1

int maxChildren(vector<int> &greed, vector<int> &cookie) {
        sort(cookie.begin(),cookie.end());
        sort(greed.begin(),greed.end());
        int c_index = 0 ,  g_index = 0 , n = cookie.size() ,  m = greed.size() , count = 0;
        while(c_index<n && g_index<m){
            if(cookie[c_index]>=greed[g_index]){
                count++;
                c_index++;
                g_index++;
            }else{
                c_index++;
            }
        }
        return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n;
    vector<int>greed(n);
    for(int i = 0 ; i < n ; i++) cin >> greed[i];
    cin >> m;
    vector<int>cookie(m);
    for(int i = 0 ; i < m ; i++) cin >> cookie[i];

    cout << maxChildren(greed,cookie);
    return 0;
}