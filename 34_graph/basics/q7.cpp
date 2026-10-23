#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(int node,vector<int>adj[],vector<bool>&visited){
        
    visited[node]=true;

    cout << node << " ";
        
    for(auto &adjNode:adj[node]){
        if(!visited[adjNode]){
            dfs(adjNode,adj,visited);
        }
    }
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N ,E;
    cin >> N >> E;
    vector<int>adj [N+1]; // 1-based indexing
    for(int i = 0 ; i < E ; i++){
        int u,v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    
    vector<bool>visited(N+1,false);
    for(int node = 1 ; node <= N ; node++){
        if(!visited[node]){
            dfs(node,adj,visited);
        }
    }

    return 0;
}


/*

10 8
1 2
1 3
2 4
3 4
5 6
5 7
6 7
8 9



8 8
1 2
1 6
2 3
2 4
4 5
6 7
6 8
7 5



*/