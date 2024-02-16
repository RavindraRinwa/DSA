#include<iostream>
#include<cstdlib>
using namespace std;
int CostFunction(int*arr,int idx,int n){
    if(idx>=n-1){
        return 0;
    }
    if(abs(arr[idx]-arr[idx+1])<abs(arr[idx]-arr[idx+2])){
       
       return  abs(arr[idx]-arr[idx+1]) +  CostFunction(arr,idx+1,n);
    }
    else{
       return  abs(arr[idx]-arr[idx+2]) + CostFunction(arr,idx+2,n);
    }
}
int main(){
    int arr[2] = {10,10};
    cout<<"The value of cost is : "<<CostFunction(arr,0,2);

}