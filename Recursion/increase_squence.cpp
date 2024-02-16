#include<iostream>
using namespace std;
void f(double N){
    if(N<1){return ;}

    f(N-1);
    cout<<N<<" ";
}
int main(){
    double N;
    cout<<"Enter the number N:";
    cin>>N;
 
    f(N);
}