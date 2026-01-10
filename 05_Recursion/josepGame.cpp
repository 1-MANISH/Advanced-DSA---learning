#include <bits/stdc++.h>
using namespace std;


void solveGame(vector<bool>&visited,int n,int k ,int start , int steps){

    // base case
    if(steps==n)return;

    int i = start , cnt = 1;
    while(cnt < k){
        if(!visited[i%n]){
            i++;
            cnt++;
        }else{
            i++;
        }
    }
    while(visited[i%n])i++;
    visited[i%n]=true;
    i = i%n +1 ;
    steps++;
    start=i%n;
    
    solveGame(visited,n,k,start,steps);
}


int main() {
    
	int n , k;
    
    cin >> n >> k;
    
    vector<bool>visited(n,false);

    solveGame(visited,n,k,0,1);

    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;

}