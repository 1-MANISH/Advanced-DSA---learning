#include <bits/stdc++.h>
using namespace std;
const int  M=1e9+7;
const int N = 1e5+10;
vector<int>factorial(N,1);

int countAnagrams(string s) {
    int  n = s.size() ;
    for(int i = 1; i<=N; i++){
        factorial[i]=((factorial[i-1]*i)%M)%M;
    }
    cout << factorial[N-1]  << endl;
    int total_anagram=0;
        string word="";
        for(int i = 0 ; i < n ; i++){
            if(s[i]== ' '){
                unordered_map<char,int>mp;
                int p = factorial[word.size()] , mul = 1;
                for(auto &ch:word){
                    mp[ch]++;
                }
                for(auto &ptr:mp){
                    if(ptr.second>1) mul = (mul*factorial[ptr.second])%M;
                }
                total_anagram+=(p/mul)%M;
                word="";
            }else{
                word+=s[i];
            }
        }
        return total_anagram;    
}

int main() {
	string str ;
	cin >> str;

	cout << countAnagrams(str) << endl;

}