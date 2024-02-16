#include<iostream>
using namespace std;

int main(){
 int arr[10] = {3,4,4,4,5,5,2,6,8,2};
 int n = sizeof(arr)/sizeof(arr[0]);
 int beg = 0;
 int end = 5;
 int mid = (beg+end)/2;
 int ans = 0;


 while(beg<=end){

    if(mid==0){
       if(arr[mid]>arr[mid+1]){
            ans = 0;
            break;
       }
       else{
            ans = 1;
               break;
       }
    }
    if(mid==n-1){
        if(arr[mid]>arr[mid-1]){
            ans =  mid;
             break;
        }
        else{
            ans = mid-1;
            break;
        }
    }

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