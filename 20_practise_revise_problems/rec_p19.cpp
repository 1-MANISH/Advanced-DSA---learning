#include<bits/stdc++.h>
using namespace std;
#define ll long long


void towerOfHanoi(int N,char src,char helper,char dest){
	if(N==0)
		return;
	towerOfHanoi(N-1,src,dest,helper);
	cout << "Move "<<src << " to " <<dest<< endl;
	towerOfHanoi(N-1,helper,src,dest);

}

int main(){

	int N;
	cin >> N;

	towerOfHanoi(N,'A','B','C');


	return 0;
}