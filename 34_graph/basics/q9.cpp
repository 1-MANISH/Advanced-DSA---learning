#include <bits/stdc++.h>
using namespace std;


// Detect cycle in graph(DFS) -  Undirected graph
bool isCycle(int node,int parent,vector<int>adjList[],vector<bool>&visited){

    visited[node]=true; 

    bool answer = false;
    // adj Node check and cycle check
    for(int &adjNode:adjList[node]){
        if(!visited[adjNode]){
            answer =  isCycle(adjNode,node,adjList,visited);
            if(answer)return true;
        }
        else if(adjNode!=parent ){
            return true;
        }
            
    }
    return answer;
   
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
            bool check = isCycle(node,-1,adj,visited);
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