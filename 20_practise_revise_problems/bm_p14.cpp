#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool checkIthBit(ll n,int i){
	return (n & (1 << i));
}

void printSubsets(vector<int>&arr,int &N){

	ll total = 1<<N;
	for(ll i = 1 ; i < total ; i++){
		for(int j = 0 ; j < N ; j++){
			if(checkIthBit(i,j)){
				cout << arr[j] << " ";
			}
		}
		cout << endl;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>arr(N);
	for(int i = 0 ; i < N ; i++)
		cin >> arr[i];

	printSubsets(arr,N);

	return 0;
}