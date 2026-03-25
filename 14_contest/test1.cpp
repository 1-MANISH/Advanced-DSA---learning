

#include<bits/stdc++.h>
using namespace std;



int main(){

	int n;
	cin >> n;
	vector<long int>colors(n);
	for(int i = 0 ; i < n ; i++){
		cin >> colors[i];
	}
	
	int ans = 0 , currentLength = 0;
	long int prev = colors[0];
	for(int i = 0  ; i < n ; i++){
		if(prev!=colors[i]){
			ans = max(ans,currentLength);
			prev= colors[i];
			currentLength=1;
		}else{
			currentLength++;
		}
	}
	cout << max(ans,currentLength) <<endl;


	
	return  0;
}