#include<bits/stdc++.h>
using namespace std;

/*
Left shift
n<<k

n<<k = n * 2^k


2^k = 1 << k

-> there is only
1 set in powers of 2


Right shift

n >> k == n / 2^k


(a+b)/2 = (a+b)>>1
int m =  (s+e)>>1


# Operation on ith Bit

1) check ith bit

 (n & (1 << i)) -> 0 -> unset
 mask =  1 << i

 2) set ith bit

 n = n | (1 << i )

 n = n | mask

 3) toggle a bit (ith bit)

  n ^ (1 << i)

4) Unset the ith bit (forcefully)
n & (~mask )

Note:
check -> n & mask
set -> n | mask
toggle -> n ^ mask
unset -> n & (~mask)
*/

bool checkIthBit(int &n,int &i){
    int mask = 1 << i;
    return (n & mask) ==0 ? 0 :1 ;

}

int setIthBit(int &n,int &i){
    int  mask = 1 << i;
    return (n | mask);
}

int toggleIthBit(int &n,int &i){
    int mask = 1 << i;
    return (n ^ mask);
}

int unsetIthBit(int &n,int &i){
    int mask = ~(1 << i);
    return (n & mask);
}

int power_2(int &k){
        return (1 << k);
}


int main(){
        int k;
        cin >> k;

        cout << power_2(k);

}