
#include<bits/stdc++.h>
using namespace std;

unsigned long long int countOfIntervals(int &t,long long int &l, long long int &r){
	unsigned  long long int counts;
	if(l>r){
		return 0;
	}
	else if(t==4 && l==r)return 1;
    else if(t!=4 && l==r) return 0;
    
	switch(t){
		case 1:
			counts = r-l-1;
			break;
		case 2:
			counts = r-l;
			break;
		case 3:
			counts = r-l;
			break;
		case 4:
			counts = r-l+1;
			break;
	}
	return counts;
}

int main(){
	
	int q;
	cin >> q;
	while(q--){
		int t;
		long long int l,r;
		cin >>t >> l >> r;	
		cout << countOfIntervals(t,l,r) << endl;
	}

	
	return  0;
}