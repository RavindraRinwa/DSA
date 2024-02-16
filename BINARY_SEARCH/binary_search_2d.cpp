#include<iostream>
using namespace std;

int main(){
    int arr[3][4] = {{1,3,5,7},{10,13,15,17},{20,23,35,37}};
    int target = 3;
    bool flag = false;
    int mid = 0;
  

    for(int i = 0;i<3;i++){
          int beg = 0;
          int end = 3;
           mid = (beg+end)/2;
         
      if(target<=arr[i][end]) {
      while(beg<=end  && arr[i][mid]!=target){  // yahe par !=target he not == target
        if(arr[i][mid]>target){
            end = mid-1;
        }
        else{
            beg = mid+1;
        }
         mid = (beg+end)/2;
      }
       
      flag = true;
    }
    if(flag){break;}
  }
  cout<<mid;
}