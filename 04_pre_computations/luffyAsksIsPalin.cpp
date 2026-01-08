#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
const int N=1e6+10;
vector<int>preComputeFN(N,0);

int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1)          // if b is odd
            result = (result *a)%M;
        a = (a * a)%M;             
        b >>= 1;            
    }
    return result;
}

int  fxn(int n){
	int powers = power(2,n-1)%M;
	int multiply =  ((n%M) * ( (n+1) % M ) )%M;
	multiply/=2;
	int res= (powers%M * multiply%M) %M;
	return res;
}

int main() {
	int t;
	cin >> t;

	for(int i = 1 ; i <= N ; i++){
		preComputeFN[i] = ( fxn(i)%M + preComputeFN[i-1]%M ) %M;
	}
	while(t--){
		int n;
		cin >> n;
		cout << preComputeFN[n] << endl;
	}
}