#include<iostream>
using namespace std;
int main()
{

    int num,sum=0,i=1;
    cout<<"Enter the number:";
    cin>>num;
    // while(i<=num)
    // {
    //   sum+=i;
    //   i++;
    // }
    do{
       sum+=i;
        i++; 
    }while(i<=num);
    cout<<"The sum of first"<<num<<"term is:"<<sum<<endl;


}