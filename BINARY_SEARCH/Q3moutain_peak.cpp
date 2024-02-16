#include<iostream>
using namespace std;


int main(){

 int arr[7] = {1,10,12,15,4,2,1};
 int beg = 0;
 int end = 6;
 int mid = (beg+end)/2;
 int ans = 0;
  
 while(beg<=end){

   if(arr[mid]>arr[mid-1]  && arr[mid]>arr[mid+1]){
        ans = mid;
        break;
   }
   else if(arr[mid]<arr[mid-1]){
        end = mid-1;
   }
   else{
        beg = mid+1;
   }
     mid = (beg+end)/2;

 }
   cout<<ans;
}