#include <bits/stdc++.h>
using namespace std;

void printSequence(long long int &number,long long int sub){
    while(number>=0){
        cout << number << " ";
        number-=sub-0LL;
    }
    cout << endl;
}


int main() {
    
    long long int a , b, c ,lcm=-1;
    cin >> a >> b >> c;
    long long int x = a < b ? a :b, y = a < b ? b :a ;
    long long int  value = x, count =  1 ,tempa=x,tempb=y;
    while(count<c){
        if(value%tempa ==0 && value%tempb ==0 && lcm==-1)lcm=value;
        if(value==18000)cout << count << "-" << x << " " << y << endl;
        if(x+tempa<=y  ){
            if(x+tempa+0LL==y)y=y+tempb+0LL;
            value=x+tempa+0LL;
            x=value+0LL;
        }
        else {
                                  
            value=y+0LL;
            y=y+tempb+0LL;
        }
        count+=1+0LL;
    }
    cout << lcm << endl;
    if(value%tempa==0 && value%tempb== 0){
        printSequence(value,lcm);
    }else if(value%tempb==0){
        printSequence(value,tempb);
    }else{
        printSequence(value,tempa);
    }
}

// https://read.learnyard.com/javascript-fundamentals/what-is-javascript/
//unicorm