#include<iostream>
int main()
{
    int num1 ,num2;
    std::cin>>num1; // std::cin>>num1>>num2;
    std::cin>>num2;

    num1 = num1+num2;
    num2 = num1-num2;
    num1 = num1-num2;
    std::cout<<"\n";
    std::cout<<num1;  // cout<<"a:"<<a<<endl;
    std::cout<<"\n";  // cout<<"b:"<<b<<endl;  
    std::cout<<num2;


}