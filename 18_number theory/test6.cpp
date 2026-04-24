/*

3) Print primes from 1 to n
SEIVE OF EROTOTHENIS
// TC = O(n*log(log(n))
// SC = O(n)
*/
#include<bits/stdc++.h>
using namespace std;

// TC = O(n*log(n))
// SC = O(n)
void printPrimses(int &n){
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i = 1 ; i*i <=n ; i++){
        if(prime[i]){
            for(int j = i*i ; j <=n ; j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        if(prime[i]){
                cout << i << endl;
        } 
    }
}


int main(){

        int n ;
        cin >> n ;
        printPrimses(n);
}