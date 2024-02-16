#include<iostream>
using namespace std;

int main(){

int arr[10] = {2,5,5,5,6,6,8,9,9,9};

 int l = 0;
 int r = 10;
 int mid = (l+r)/2;
 int target = 5;
 int ans = -1;


while( l<=r){


   if(arr[mid]>target){
       r = mid-1;
   }
 else if(arr[mid]==target){
      ans = mid;
      r = mid-1;
   }
   else{
      l = mid+1;
   }
 
   mid = (l+r)/2;

 }

cout<<"The lowest index is :"<<ans;
    return 0;
}