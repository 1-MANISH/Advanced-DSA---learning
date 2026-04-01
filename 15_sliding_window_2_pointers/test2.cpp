/*Q:

Count vowels in every substring of size = k

*/
#include<bits/stdc++.h>
using namespace std;

int isVowel(char &ch){
	if(ch=='A' || ch == 'a' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u')
		return 1;
	else return 0;
}

void vowelsInSubStringSizeK(string &str,int &n , int &k){
	int numVowels = 0;
	for(int i = 0 ; i< k ; i++){
		numVowels+=isVowel(str[i]);
	}	
	cout << numVowels << " ";
	for(int i = k ; i < n ; i++){
		numVowels=numVowels+isVowel(str[i])-isVowel(str[i-k]);
		cout << numVowels << " ";
	}
}

int main(){

	int n , k;
	cin >> n >> k ;
	string str;
	cin >> str;

	vowelsInSubStringSizeK(str,n,k);

	
	return  0;
}