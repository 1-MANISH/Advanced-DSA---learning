/*

3) Count factors of all numbers from 1 to n
// TC = O(n*log(n))
// SC = O(n)
*/
#include<bits/stdc++.h>
using namespace std;

// TC = O(n*log(n))
// SC = O(n)
void countFactors(int &n){
    vector<int>factors(n+1,0);
    for(int i = 1 ; i <=n ; i++){
        for(int j = i ; j <=n ; j+=i){
            if(j%i==0){
                factors[j]++;
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        cout << i << " -> " << factors[i] << endl; 
    }
}


int main(){

        int n ;
        cin >> n ;
        countFactors(n);
}