#include<iostream>
using namespace std;
int main(){

int arr[7] = {4,5,6,7,0,1,2};
   int beg = 0;
   int end = 6;
   int mid = (end+beg)/2;
   int ans = 0;

   if(arr[beg]<arr[end]){
        cout<<beg;
   }

   if(arr[beg]>arr[end]){
         while(beg<=end){

     if(arr[0]<arr[mid]){
        beg = mid+1;
     }
     else{
        ans = mid;
        end = mid-1;
      }
      mid = (beg+end)/2;
   }
     cout<<ans;
   }

}