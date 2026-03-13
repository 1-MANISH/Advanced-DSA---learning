

// count of vowels in string
// on range [L....R]

/*
Input
10
abacodeeee
3
1 3
4 7
5 10


output:
2
2
5

*/
#include<bits/stdc++.h>
using namespace std;



int main(){
	int n ;
	string str;
	cin >> n >> str;
	vector<int>pvCount(n+1,0);
	int vCount = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
			vCount++;
		}
		pvCount[i+1]=vCount;
	}


	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << pvCount[r]-pvCount[l-1]<< endl;
		
	}
	
	return  0;
}