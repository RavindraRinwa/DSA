#include<iostream>
using namespace std;
bool Check(int*arr,int n,int x,int idx){
    if(idx==n){
      return false;
    }
    else{
        return (arr[idx]==x) || Check(arr,n,x,idx+1);
    }
}
int main(){
    int arr[10] = {1,2,3,-9,-8,7,6,-5,4,8};
    int n = 10;
    int x = -8;
    Check(arr,n,x,0);
    if(Check){
        cout<<"YES";
    }
    else{cout<<"NO";}
}