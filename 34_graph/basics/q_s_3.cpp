
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/C
vector<vector<int>>paths;

void bfs(int &node,vector<int>adjList[],vector<bool>&visited){

    queue<int>q;
    q.push(node);
    visited[node]=true;
    vector<int>path;

    while(!q.empty()){
        int c_node = q.front();
        q.pop();
        path.push_back(c_node);

        // adjNode
        for(int &adjNode:adjList[c_node]){
            if(!visited[adjNode]){
                q.push(adjNode);
                visited[adjNode]=true;
            }
        }
    }
    paths.push_back(path);
    
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
    for(int node  = 1 ; node <= n ; node++){
        if(!visited[node]){
            bfs(node,adjList,visited);
        }
    }

    cout << paths.size() << endl;
    for(auto &path:paths){
        cout << path.size() << " ";
        for(auto &pathEle:path)cout << pathEle << " ";
        cout << endl;
    }
    

    
    return 0;
}
