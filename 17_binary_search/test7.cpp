/*

There is string with leading True
and Trailing False find
Last True


*/
#include<bits/stdc++.h>
using namespace std;

int lastTrueIndex(string &str,int &n){
	int start = 0 ,  end=n-1 , ans = -1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(str[mid]=='T'){
			ans = mid;
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return ans;
}

int main(){

	int n;
	cin >> n;
	string str;
	cin >> str;


	cout << lastTrueIndex(str,n) << endl;

}