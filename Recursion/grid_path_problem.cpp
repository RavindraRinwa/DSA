#include<iostream>
using namespace std;
int GridFunction(int m,int n){
    if(m==1 || n==1){
        return 1;
    }
    else{
       return  GridFunction(m-1,n)+GridFunction(m,n-1);
    }
}
int main(){
    cout<<"The number of total path is :"<<GridFunction(3,3);
}