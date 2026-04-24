/*

Print factors of number from 1 to N
TC = O(n*log(n))
Sc= O(sum of factors[i].size())
*/

// TC = O(n*log(n))
// Sc= O(sum of factors[i].size())

#include<bits/stdc++.h>
using namespace std;

void printFactors(int &n){
     vector<vector<int>>factors(n+1,vector<int>());
     for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <=n ; j+=i){
             if(j%i==0){
                factors[j].push_back(i);
             }
        }
     }
     for(int i = 1 ; i <=n;i++){
        cout << i << " -> ";
        for(auto &factor:factors[i])
                cout << factor << " ";
        cout << endl;
     }
}


int main(){

    int n ;
    cin >> n ;
    printFactors(n);
}