
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


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
    vector<int>factors(N+1,0);
    for(int i = 1 ; i <=N ; i++){
           for(int j = i ; j <=N ; j+=i){
               if(j%i==0){
                   factors[j]++;
               }
            }
    }

    while(n--){
        int q;
        cin >> q;
        cout << (prime[factors[q]]?"YES\n":"NO\n");
    }
    return 0;
}