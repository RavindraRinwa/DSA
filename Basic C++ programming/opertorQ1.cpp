#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = a++; // b=a and then a=11;
    cout<<b<<" ";
    b=++a;  //b=12 and then a=12;
    cout<<a;
    return 0;
}