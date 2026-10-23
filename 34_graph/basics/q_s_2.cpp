
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/B

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
    int a,b;
    cin >> a >> b;
    vector<bool>visited(n+1,false);
    queue<int>q;
    q.push(a);
    visited[a]=true;
    bool flag = false;
    while(!q.empty()){
        if(flag)break;
        int node = q.front();
        q.pop();

        // put its adjacent node
        for(int &adjNode:adjList[node]){
            if(!visited[adjNode]){
                visited[adjNode]=true;
                q.push(adjNode);
                if(adjNode==b){
                    flag=true;
                    break;
                }
            }
        }
    }

    if(flag or visited[b])cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
