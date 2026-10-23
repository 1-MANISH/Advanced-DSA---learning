#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // directed graph
    int n,m;
    cin >> n >> m;
    // n = nodes
    // m = edges
    // 1 based indexing
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int u,v;
        // u---> v
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}
