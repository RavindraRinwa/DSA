#include<iostream>
using namespace std;
int main()
{
    int decimal_number,binary_number = 0,parity_digit = 0,power = 1;
    cin>>decimal_number;
    while(decimal_number!=0){
      parity_digit = decimal_number%2;
      binary_number+=parity_digit*power;//power=1 because 10 ki power 0 =1
      power*=10;
      decimal_number = decimal_number/2;
    }
    cout<<binary_number;
}