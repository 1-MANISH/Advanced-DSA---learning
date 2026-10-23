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
    int adj[n+1][m+1];
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        // u---> v
        cin >> u >> v >> w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    return 0;
}
