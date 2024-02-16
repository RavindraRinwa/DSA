#include<iostream>
using namespace std;
int Binary_function(int arr[],int target,int l,int r){
    
    int mid = (l+r)/2;  // for reduce the error of overflow we need modify over mid like l + (r-l)/2

    if(left>right){
        return -1;
    }
    else if(arr[mid]==target){
        return mid;
    }
    else{
        if(arr[mid]>target){
            return  Binary_function(arr,target,mid+1,r);
        }
        else{
            return  Binary_function(arr,target,l,mid-1);
        }
    }
}
int main(){

int arr[10] = {1,23,45,67,34,2,455,445,44,56};

  int flag = Binary_function(arr,45,0,10);

  if(flag>=0){
      cout<<"The is present in array and the index of element is:"<<flag;
  }
  else{
      cout<<"The element is not present in array";
  }

    return 0;
}