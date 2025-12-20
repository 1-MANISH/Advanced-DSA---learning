#include<bits/stdc++.h>
using namespace std;


// 1 primality check
// O(sqrt(n))
bool isPrime(int n){
        if(n<=1)return false;
        for(int x  = 2 ; x*x<=n ; x++){
                if(n%x==0)return false;
        }
        return true;
}

bool isComposite(int n){
        return !isPrime(n);
}

vector<int> printFactors(int n){
        vector<int>pFactors;
        for(int x = 2 ; x*x <= n ; x++){
                while(n%x==0){
                        pFactors.push_back(x);
                        n /= x;
                }
        }
        if(n>1)pFactors.push_back(n);
        return pFactors;
}

int main(){
       

        int n;
        cin >> n;

        if(isPrime(n)){
                cout << n << " is prime\n";
        }
        else{
                cout << n << " is not prime\n";
        }

        vector<int> factors = printFactors(n);
        cout << "Factors of " << n << " are : ";
        for(auto x : factors){
                cout << x << " ";
        }
        cout << endl;

        return 0;
}