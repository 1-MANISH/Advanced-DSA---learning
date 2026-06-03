
#include<bits/stdc++.h>
using namespace std;


int main(){

   	int n;
   	cin >> n;
    int N = 1e6;
   	vector<bool>prime(N+1,true);
    prime[0]=prime[1]=false;
    for(int i = 2 ; i <=N/i ; i++){
        if(prime[i]){
            for(int j = i*i  ; j<=N ; j+=i){
                prime[j]=false;
            }
        }
    }

    while(n--){
        int q;
        cin >> q;
        cout << (prime[q]?"YES\n":"NO\n");
    }
    return 0;
}