#include <bits/stdc++.h>
using namespace std;

void findPostion(int &x,int &y){
    if(x==0 && y==0)cout<< "Origin\n";
    else if(x==0 && y!=0)cout << "X axis\n";
    else if(y==0 && x!=0)cout << "Y axis\n";
    else if(x>0 && y>0)cout << "1st Quadrant\n";
    else if(x<0 && y>0)cout << "2nd Quadrant\n";
    else if(x<0 && y< 0) cout << "3rd Quadrant\n";
    else if(x>0 && y < 0) cout << "4th Quadrant\n";
}

int main() {
   int x,y;
   cin >> x>> y;

   findPostion(x,y);
}

  