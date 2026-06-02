
/*
x^n
*/
#include<bits/stdc++.h>
using namespace std;


long long int xraisn(long long int &x,long long int &n){
        long long int ans = 1;
        for(int i = 1 ; i <= n ; i++)
                ans = ans*x;
        return ans;
}

int main(){

        long long int x, n ;
        cin >> x >> n ;
        cout << xraisn(x,n) << endl;
}