#include<iostream>
using namespace std;
void f(int N){
    if(N%2==0){
       int sumO = (N*N)/4;
       int sumE = (N*(2+N))/4;

       cout<<"The sum of series is :"<<sumO-sumE;
    }
    else{
        int sumO = ((N+1)*(N+1))/4;
        int sumE = ((N-1)*(N+1))/4;

        cout<<"The sum of series is:"<<sumO-sumE;
    }
}
int main(){
    int N;
    cout<<"Enter the value of N:";
    cin>>N;

    f(N);
}