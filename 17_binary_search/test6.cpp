/*

There is string with leadin False
and Trailing True find
first True


*/
#include<bits/stdc++.h>
using namespace std;

int firstTrueIndex(string &str,int &n){
	int start = 0 ,  end=n-1 , ans = -1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(str[mid]=='T'){
			ans = mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return ans;
}

int main(){

	int n;
	cin >> n;
	string str;
	cin >> str;


	cout << firstTrueIndex(str,n) << endl;

}