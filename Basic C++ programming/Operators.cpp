#include<iostream>
using namespace std;
int main()
{
    int num1 = 5,num2 = 2;
    // in also c++ divid give integer  

    // ~ bitwise complement
    // << left shift  
    // a<<b then you get a*pow(2,b) in decimal form
    // a>>b then you get a/pow(2,b) in decimal form
    // bitwise and operator-> & or->| and xor -> ^
     num1 =  num1<<num2;
     cout<<num1<<endl;// 5->0101(beacuse 4 bit int data type)  5*pow(2,num2)->20

     num1=5;num2=2;
     cout<<(num1 | num2)<<endl;//->7
     cout<<(num1 & num2)<<endl;//->0
     cout<<(num1^num2)<<endl;//->7

      cout<<sizeof(int)<<endl;//sizeof(num1)->4

      //conditional operator is also same as C language
      // comma operator  int y = 1,2,3;  y = last value->3
      // type casting happen this type int() not like C language
      //a++ or a-- ->post increment
      //++a or --a ->pre increments

    //   cout<<(num1+num2+"pqr")<<endl; // + - ->left to right
    //   cout<<("pqr"+num1+num2)<<endl;  //"pqr"+4 = pqr4 and so...
      
     int s= num1+++num2---num1;  // for q num1 and num1 value are changed
     int q = ++num1+--num2-num1;

     cout<<"s:"<<s<<std::endl;  // ++ -- > + -
     cout<<"q:"<<q<<std::endl;

    // == has piriorty as left to right

      }