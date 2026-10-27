
#include <bits/stdc++.h>
using namespace std;


// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/D


void bfs(int node,vector<int>adjList[],vector<bool>&visited){

    queue<int>q;
    q.push(node);
    visited[node]=true;
  

    while(!q.empty()){
        int c_node = q.front();
        q.pop();
      
        // adjNode
        for(int &adjNode:adjList[c_node]){
            if(!visited[adjNode]){
                q.push(adjNode);
                visited[adjNode]=true;
            }
        }
    }
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;
    vector<int>adjList[n+1];
    for(int i = 1 ; i <=m ; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }



    vector<bool>visited(n+1,false);
    bfs(1,adjList,visited);
    vector<int>leaders;
    for(int node  = 1 ; node <= n ; node++){
        if(!visited[node]){
            bfs(node,adjList,visited);
            leaders.push_back(node);
        }
    }
    cout << leaders.size() << endl;
    for(int &leader :leaders ){
        cout << 1 << " "<< leader << endl;
    }
    
    

    
    return 0;
}
