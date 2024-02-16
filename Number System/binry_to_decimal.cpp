#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int binary_number,i=0,decimal_number = 0;
    cin>>binary_number;
    while(binary_number!=0){
       decimal_number+=(binary_number%10)*pow(2,i);
       binary_number = binary_number/10;
       i++;
    }
    cout<<decimal_number;
}