#include <bits/stdc++.h>
using namespace std;

// pass bby value
void increamentByPassByValue(int x){
    x++;
}

// pass by reference
void increamentByPassByReference(int &x){
    x++;
}

// pass by pointers
void increamentByPassByPointer(int *p){
    // *p = *p + 1;
    (*p)++;
}

int main() {

    // charcha on passing pointers to the functions
    int a = 4;
    cout << a << endl;
    increamentByPassByValue(a);
    cout << a << endl;

    cout << a << endl;
    increamentByPassByReference(a);
    cout << a << endl;

    cout << a << endl;
    increamentByPassByPointer(&a);
    cout << a << endl;

    // double pointer pe charcha
    // int x = 9;
    // int *p = &x;
    // int **q = &p;

    // cout << x << " " << *p << " " << **q << endl;
    // cout << &x << " " << p << " " << *(q) <<endl;
    // cout <<  &p << " " << q << endl;


    // arrays charha

    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // cout << arr << " " << &arr[0] << endl;
    // cout << arr+1 << " " << &arr[1] << endl;


    // cout << *arr << " " << arr[0] << " " << *(&arr[0]) << endl;
    // cout << *(arr+1) << " " << arr[1] << " " << *(&arr[1]) << endl;
    // cout << *(arr+2) << " " << arr[2] << " " << *(&arr[2]) << endl;


    // normal charcha

    // int x = 5, y = 10 , z = 15;

    // int *p_x = &x;
    // int *p_y = &y;
    // int *p_z = &z;

    // cout<< "address of x : " << p_x << endl;
    // cout<< "address of y : " << p_y << endl;
    // cout<< "address of z : " << p_z << endl;

    // cout << x <<  " " <<  y << " " << z << endl;

    // cout << *p_x << " " << *p_y <<  " " << *p_z << endl;

    // *p_x = *p_x * 100;
    // *p_y *= 100;
    // ++*p_z;

    // cout << x <<  " " <<  y << " " << z << endl;
    return 0;
}
