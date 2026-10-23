
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>adjList[n+1];
    for(int i = 0 ; i < n-1 ; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i++){
        if(adjList[i].size()==n-1){
            cout << i << endl;
            break;
        }
    }

    
    return 0;
}
