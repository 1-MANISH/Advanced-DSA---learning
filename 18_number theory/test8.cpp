/*

Print prime factors 

// TC = O(root(N))
// SC = O(1)
*/
#include<bits/stdc++.h>
using namespace std;
// TC = O(root(N))
// SC = O(1)
void printPrimeFactors(int n){
    for(int i = 2 ; i*i<=n ; i++){
        if(n%i==0){
            while(n%i==0 ){
                cout << i << " ";
                n = n/i;
            }
        }
    }
    
}

int main(){

        int n ;
        cin >> n ;
        printPrimeFactors(n);
}