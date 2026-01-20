// https://codeforces.com/gym/102892/my
    
#include<bits/stdc++.h>
using namespace std;


void infectedLatters(string &s,int i,int &n){

	if(i==n){
		return;
	}
	int j = i ;
	while(j<n && s[j]!='a')j++;

	// now we have 'a' position check if we can infect on both left or right
	if(j>=1 && j< n){//left check
		int k = j-1;
		while(k>=0 && s[k]!='b' && s[k]!='a')s[k--]='a';
		
	}
	if(j+1<n){//right check
		int k = j+1;
		while(k<n && s[k]!='b')s[k++]='a';
		infectedLatters(s,k,n);
	}

}

int main(){
	int n;
    string s;
    cin >> n>> s;

    infectedLatters(s ,0 , n);

    int aInfected = 0;
    for(char &ch:s)if(ch=='a')aInfected++;
    cout << aInfected << endl;
    return 0;
}