#include<bits/stdc++.h>
using namespace std;


bool isChar(char &ch){
	if(ch>='a' && ch<='z')return true;
	return false;
}
  bool validWordAbbreviation(string word, string abbr) {
        int index = 0 ,  i = 0 , n = word.size(),m = abbr.size() ,flag=0;
        // if contains more any 0's than return false
        for(int i = 0 ; i < m ; i++ ){
            if(!flag && abbr[i]=='0')return false;
            else if(abbr[i]>='1' && abbr[i]<='9'){
                flag=1;
                break;
            }
        }
        
        while( index<n && i<m ){
        	cout << i << " " << index << endl;
            if(isChar( abbr[i])){
                if(index<n && i<m && word[index]!=abbr[i])return false;
                else index++,i++;
            }else{
                int digit = 0;
                while(i<m && abbr[i]>='1' && abbr[i]<='9'){
                    digit = digit*10+abbr[i]-'0';
                    i++;
                }
                
                if( index+digit>n )return false;
                if(index+digit==n)return true;
                if( word[index+digit]!=abbr[i])return false;
                else i++ , index = index+digit+1;
            }
        }
        if(i==m || index==n)return true;
        return false;
 }
int main(){
	int q;
	string word , abbr;
	cin >> word >> q ;
	while(q--){
		cin >> abbr;
		cout << validWordAbbreviation(word,abbr)<< endl;
	}



	return 0;
}