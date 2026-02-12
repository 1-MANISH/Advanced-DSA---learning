#include<bits/stdc++.h>
using namespace std;


int main(){
    string w1,w2;
    cin>>w1>>w2;

    int n = w1.size(),m = w2.size();
    for(int i = 0; i < min(n,m);i++){
        if(w1[i]==w2[i]){
            continue;
        }else if(w1[i]<w2[i]){
            cout << "A\n";
            return 0;
        }else{
            cout<< "B\n";
            return 0;
        }
    }
    if(n<m){
        cout << "A\n";
    }else if(n>m){
        cout << "B\n";
    }else
        cout << "Equal\n";

    return  0;
}
