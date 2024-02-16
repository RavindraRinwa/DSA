#include<iostream>
using namespace std;
int main()
{
    int num,number_of_digit = 0,sum = 0;
    cin>>num;
    for(int i = 1;i>0;i=num)
    {
       sum+=num%10;
       num= num/10;
       number_of_digit++;
    }
    cout<<"The sum of digit of given number is:"<<sum<<endl;
    cout<<"The number of digit present in given number is:"<<number_of_digit<<endl;
}