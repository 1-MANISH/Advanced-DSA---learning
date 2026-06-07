#include<bits/stdc++.h>
using namespace std;

void printAllPossiblePath(int &n,int &m,int i,int j ,string &path){

	if(i==n && j == m){
		cout << path<<endl;
		return;
	}
	if(i>n || j>m)
		return;

	// lets take right
	path.push_back('R');
	printAllPossiblePath(n,m,i,j+1,path);
	path.pop_back();

	// lets take down
	path.push_back('D');
	printAllPossiblePath(n,m,i+1,j,path);
	path.pop_back();
}

int main(){

	int n,m;
	cin >> n >> m;
	string path = "";

	printAllPossiblePath(n,m,1,1,path);

	return 0;
}