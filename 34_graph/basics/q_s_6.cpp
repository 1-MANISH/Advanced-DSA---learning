
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/F

void bfs(int src,vector<int>adjList[],vector<bool>&visited,vector<int>&distance){

    queue<pair<int,int>>q;//{node,dist}
    q.push({src,0});
    visited[src]=true;
    distance[src]=0;

    while(!q.empty()){
      
        auto [node,dist] = q.front();
        q.pop();

        // put its adjacent node
        for(int &adjNode:adjList[node]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push({adjNode,dist+1});
                distance[adjNode]=dist+1;
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

    vector<int>distance(n+1,-1);
    vector<bool>visited(n+1,false);
    bfs(1,adjList,visited,distance);
    for(int node=2 ; node<=n;node++)
        cout << distance[node] << " ";
    
    return 0;
}
