/*

Q:

Print power of 2 <= N
*/

#include<bits/stdc++.h>
using namespace std;

void printPower2(int &n){
        int ans = 1;
        for(int i = 1 ; ans <=n ; i++){
                cout << ans << " ";
                ans = ans*2;
        }
}

int main(){

        int n ;
        cin >> n ;
        printPower2(n);
}