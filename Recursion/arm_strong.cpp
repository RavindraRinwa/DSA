#include<iostream>
using namespace std;
int result = 0;
int pow(int base,int power){
       if(power==1){
          return base;
       }
       if(power%2==0){
           result = pow(base,power/2);
           return result*result;
       }
       else{
           result = pow(base,(power-1)/2);
           return  base*result*result;
       }
}
int f(int N,int d){
      if(N==0){
            return 0;
      }
      else{
           return pow(N%10,d)+f(N/10,d);
      }
}
int main(){
    int N,copy,count = 0;
    cout<<"Enter the number N:";
    cin>>N;

    copy = N;
    while(N!=0){
        count++;
        N = N/10;
    }
    
    if(copy==f(copy,count)){
        cout<<"The given number is a ARMSTRONG  number";
    }
    else{
        cout<<"The given number not ARMSTORNG NUMBER ";
    }
}