
#include<bits/stdc++.h>
using namespace std;



int main(){

	long long int n , k;
	cin >> n >> k; 

	long long int factor = 1; 
	vector<long long int>factors;

	long long int mul = factor*factor;
	while(mul<=n){
		long long int j = n/factor;

		if(n%factor==0){
			factors.push_back(factor);
			if(factor!=j)
			factors.push_back(j);
		}
		factor++;
		mul = factor*factor;
	}

	if(factors.size()<k){
		cout << -1 << endl;
		return 0;
	}

	sort(factors.begin(),factors.end());
	
	cout << factors[k-1] << endl;


	
	return  0;
}