#include <bits/stdc++.h>
using namespace std;

// BFS

void bfs(int node,vector<int>adj[],vector<bool>&visited){

    visited[node]=true;
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        // put its adjacent into queue if not traversed

        for(auto &adjNode:adj[currentNode]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push(adjNode);
            }
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

    // traversal -  may be disconnected component
    vector<bool>visited(N+1,false);
    for(int node = 1 ; node <= N ; node++){
        if(!visited[node]){
            bfs(node,adj,visited);
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