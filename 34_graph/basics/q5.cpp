#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // weighted graph
    int n,m;
    cin >> n >> m;
    // n = nodes
    // m = edges
    // 1 based indexing
    vector<pair<int,int>> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
 
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return 0;
}
