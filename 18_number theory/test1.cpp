
/*
1) Print factors of a number
*/
#include<bits/stdc++.h>
using namespace std;


// TC = O(√n) , SC = o(1)
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
     }
}

int main(){

    int n ;
    cin >> n ;

    printFactors(n);


        
}