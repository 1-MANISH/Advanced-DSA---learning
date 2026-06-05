#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

	int N;
	cin >> N;
	ll andAnswer=1,orAnswer=0,xorAnswer=0;
	for(int i = 0 ; i< N ; i++){
		ll arrEle;
		cin >> arrEle;

		andAnswer =(i==0?arrEle : andAnswer&arrEle);
		orAnswer = orAnswer|arrEle;
		xorAnswer = xorAnswer^arrEle;
	}

	cout << andAnswer << " "<<orAnswer<< " "<< xorAnswer<<endl;

	return 0;
}