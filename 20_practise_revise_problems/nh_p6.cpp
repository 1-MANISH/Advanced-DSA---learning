
#include<bits/stdc++.h>
using namespace std;


int main(){


    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

   	int n,q;
   	cin >> n>>q;
   	vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i = 2 ; i <=n/i ; i++){
        if(prime[i]){
            for(int j = i*i  ; j<=n ; j+=i){
                prime[j]=false;
            }
        }
    }

    vector<int>prefix(n+1,0);
    for(int i = 2 ;  i <=n;i++){
        prefix[i]=prefix[i-1]+(prime[i]?1:0);
    }


    while(q--){
        int l,r;
        cin >> l>>r;
        cout << (prefix[r]-prefix[l-1])<< endl;
    }
    return 0;
}