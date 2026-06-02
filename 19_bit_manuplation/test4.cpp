#include<bits/stdc++.h>
using namespace std;


/*
Print binary of a number

*/

void print_binary(int n){

        int h_p  =  1;
        while(h_p<=n){
                h_p*=2;
        }
        h_p/=2;
        while(h_p>0){
                if(h_p<=n){
                        cout << 1 ;
                        n-=h_p;
                }else{
                        cout << 0;
                }
                h_p/=2;
        }

}
int main(){

        int n ;
        cin >> n ;
        print_binary(n);
}