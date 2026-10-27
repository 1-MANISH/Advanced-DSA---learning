
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/726913/problem/G

// multi source BFS
void bfs(vector<int>adjList[],vector<bool>&visited,vector<int>&distance,vector<int>&hospitals){

    queue<pair<int,int>>q;//{node,dist}
    for(int hospital:hospitals){
        q.push({hospital,0});
        visited[hospital]=true;
        distance[hospital]=0;
    }
    

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
    int k;
    cin >> k;
    vector<int>hospitals;
    while(k--){
        int hospital;
        cin >> hospital;
        hospitals.push_back(hospital);
    }
    bfs(adjList,visited,distance,hospitals);
    for(int node=1 ; node<=n;node++)
        cout << distance[node] << " ";
    
    return 0;
}
