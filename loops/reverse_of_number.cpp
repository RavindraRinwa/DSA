#include<iostream>
using namespace std;
int main()
{
    int num,last_digit,reverse =0;
    cin>>num;
    for(int i = 1;i>0;i=num)
    {
        // reverse_digit = num%10;
        // num = num/10;
        // cout<<reverse_digit;
        
        last_digit = num%10;
        reverse = reverse*10+last_digit;
        num = num/10;
    }
    cout<<reverse;
}