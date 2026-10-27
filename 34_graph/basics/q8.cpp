#include <bits/stdc++.h>
using namespace std;


// Detect cycle in graph(BFS) -  Undirected graph
bool isCycle(int node,vector<int>adjList[],vector<bool>&visited){

    queue<pair<int,int>>q;//{node,parent-where it come from}
    q.push({node,-1});
    visited[node]=true;

    while(!q.empty()){
        auto[n,p] = q.front();
        q.pop();

        // visits its adjacent and check if loop or not
        for(int &adjNode:adjList[n]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push({adjNode,n});
            }else{
                if(adjNode!=p)return true;
            }
        }
    }
    return false;
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
            bool check = isCycle(node,adj,visited);
            if(check){
                cout << "CYCLE\n";
                return 0;
            } 
        }
    }

    cout << "NO CYCLE\n";
   

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