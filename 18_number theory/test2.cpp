/*

Print factors of number from 1 to N
TC = O(n*√n)
Sc= O(1)
*/

// TC = O(n*√n)

#include<bits/stdc++.h>
using namespace std;

void printFactors(int &n){
     for(int i = 1 ; i <=n/i ; i++){
        if(n%i == 0){
            cout << i << " ";
        }
        
     }
     int i = sqrt(n);
     while(i >= 1){
        if(n%i==0){
           int j = n/i;
           if(i!=j)cout << j << " ";
        }
        i--;
     }cout << endl;
}


int main(){

    int n ;
    cin >> n ;
    for(int i =1 ; i<= n ; i++){
        cout << i << "-> ";
        printFactors(i);
    }
}