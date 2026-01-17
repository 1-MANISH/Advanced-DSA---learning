#include<bits/stdc++.h>
using namespace std;


/*

comparatore
	if wants to swap - return false
	else return true

	Trick to remember -
	
	Jis order me chaiye vo return krdo
	
*/

void printArr(vector<int>&arr){
	for(auto &ele:arr)cout << ele << " ";
		cout << endl;
}

bool compartorFunction(int &a,int &b){
	// if(a>b){
	// 	// swap krna pdega
	// 	return false;
	// }else{
	// 	return true;
	// }

	return a<b;
	// return a>b;


}
int main(){

		int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >>arr[i];
   
    printArr(arr);
    sort(arr.begin(),arr.end(),compartorFunction);
 		printArr(arr);


		return 0;
}