#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9+7;

//0 1 1 2 4 7 13....

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n==0){
        cout << 0;
        return 0;
    }
    else if(n<=2){
        cout << 1;
        return 0;
    }
    ll a   =  0 ,  b = 1 ,c = 1;

    for(int i = 3 ; i <= n ;i++){
        ll temp = c;
        c = (a+b+c)%M;
        a = b;
        b = temp;
    }

    cout << c << endl;

    return 0;
}