/*

Q:

N= 51

Have to represent N as sum of powers of 2
(No repetition allowed)
*/

#include<bits/stdc++.h>
using namespace std;

void bruteForce_2_power_sum(int &n){
        int current  =1;
        while(current<=n){
                current*=2;
        }
        current/=2;

        int m = n;
        while(current>=1){
            if(m>=current){
                m-=current;
                cout << current << (m!=0 ? " + ":"");
            }
            current/=2;
        }
}

void reprentAt_2_power_sum(int n){
        int power = 1;
        while(n >= 1){
            int rem = n%2;
            n /=2;
            if(rem==1)cout << power << (n!=0 ? " + ":"");
            power*=2;
        }
}

int main(){

        int n ;
        cin >> n ;
        bruteForce_2_power_sum(n);
}