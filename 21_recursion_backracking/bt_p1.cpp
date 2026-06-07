
#include<bits/stdc++.h>
using namespace std;

void printPath(vector<int>&path){
   for(int &ele:path)cout << ele << " ";
   cout << endl;
}


void printAllValidPath(int n,int rem,vector<int>path){

   if(rem==0){
      printPath(path);
      return;
   }

   // take 1step
   path.push_back(1);
   printAllValidPath(n,rem-1,path);
   path.pop_back();

   // if possible then take 2 steps
   if(rem>=2){
      path.push_back(2);
      printAllValidPath(n,rem-2,path);
      path.pop_back();
   }

}

int main(){

	int n ;
	cin >> n;
	
   printAllValidPath(n,n,{});


	return 0;
}