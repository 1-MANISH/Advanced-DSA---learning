#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checkBit(ll n,int &i){
	return ((n & (1<<i)) !=0 ); 
}
ll setBit(ll n,int &i){
	return (n | (1<<i));
}

ll unSetBit(ll n,int &i){
  return (n & (~(1<<i)) );
}

ll toggleBit(ll n,int &i){
	return (n ^ (1<<i));
}

int main(){

	ll N;
	int q;
	cin >> N >> q;

	while(q--){
		int t,i;
		cin >> t>>i;
		if(t==1){
			cout << (checkBit(N,i)?"YES\n":"NO\n");
		}else if(t==2){
			N=setBit(N,i);
			cout << N <<endl;
		}
		else if(t==3){
			N=unSetBit(N,i);
			cout << N <<endl;
		}else if(t==4){
			N=toggleBit(N,i);
			cout << N << endl;
		}
	}

	return 0;
}