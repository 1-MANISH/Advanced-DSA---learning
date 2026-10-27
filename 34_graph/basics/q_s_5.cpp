
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/B

void bfs(int src,vector<int>adjList[],vector<bool>&visited,vector<int>&leaders){

    queue<int>q;
    q.push(src);
    visited[src]=true;
    leaders[src]=src;

    while(!q.empty()){
      
        int node = q.front();
        q.pop();

        // put its adjacent node
        for(int &adjNode:adjList[node]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push(adjNode);
                leaders[adjNode]=src;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int>adjList[n+1];
    for(int i = 1 ; i <=m ; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool>visited(n+1,false);
    vector<int>leaders(n+1,-1);
    for(int node = 1 ; node <= n ; node++){
        if(!visited[node]){
            bfs(node,adjList,visited,leaders);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        if(leaders[a]==leaders[b])cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
