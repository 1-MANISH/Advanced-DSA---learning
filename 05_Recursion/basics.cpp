#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
vector<long long int>saved(M,-1); 

long long int factorial(int n){
    if(n<=0)return 1;
    if(saved[n]!= -1){
        return saved[n];
    }
    saved[n]= n*factorial(n-1);
    return saved[n];
}

int main() {
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << n <<"! = "<<factorial(n) << endl;
    }
	
}