
#include<bits/stdc++.h>
using namespace std;


int main(){

   	int n,count = 0;
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

    for(int i = 2 ; i<=n ; i++){
       
        if(prime[i])cout<< i << " ", count++;
    }
    cout << endl;
    cout << count << endl;
      

	return 0;
}