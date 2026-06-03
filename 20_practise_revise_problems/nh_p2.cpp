
#include<bits/stdc++.h>
using namespace std;


int main(){

   	int n ;
   	cin >> n;
      int N = 1e6;
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
         cout << factors[q]<< "\n";
      }

	  return 0;
}