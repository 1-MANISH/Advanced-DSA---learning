/*

Print prime factors for q queries

// TC = O(n*log(log((N))
// SC = O(n)
*/
#include<bits/stdc++.h>
using namespace std;
// TC = O(n*log(log((N))
// SC = O(n)

void printPrimeFactors(int n){

    vector<int>spf(n+1,1);
    for(int i = 2 ; i <=n ; i++)
        spf[i]=i;
    for(int i = 2 ; i*i<=n ; i++){
        if(spf[i]==i){// prime no 
            for(int j = i*i ; j <=n ; j+=i){
                if(spf[j]!=i){
                    spf[j]=i;
                }
            }   
        }
    }
    while(n != 1){
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main(){

        int n ;
        cin >> n ;
        printPrimeFactors(n);
}