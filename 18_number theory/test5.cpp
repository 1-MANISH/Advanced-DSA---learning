/*

3) Print primes from 1 to n
// TC = O(n*log(n))
// SC = O(n)
*/
#include<bits/stdc++.h>
using namespace std;

// TC = O(n*log(n))
// SC = O(n)
void printPrimses(int &n){
    vector<int>factors(n+1,0);
    for(int i = 1 ; i <=n ; i++){
        for(int j = i ; j <=n ; j+=i){
            if(j%i==0){
                factors[j]++;
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        if(factors[i]==2){
                cout << i << endl;
        } 
    }
}


int main(){

        int n ;
        cin >> n ;
        printPrimses(n);
}