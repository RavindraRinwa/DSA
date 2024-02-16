#include<iostream>
#include<vector>
using namespace std;
void Merge(int*arr,int l,int mid,int r){
    int an = mid-l+1;
    int bn = r-mid;

    int a[an];  
    int b[bn];
    
    for(int i = 0;i<an;i++){
        a[i] = arr[l+i];
    }
    for(int j = 0;j<bn;j++){
        b[j] = arr[mid+1+j];
       }  

       int j = 0;  // intial index of first subarray
       int i = 0;  // intial index of second subarray
       int k = l;  // intial index of merged subarray

       while(i<an && j<bn){
           if(a[i]<b[j]){
               arr[k++] = a[i++];
           }
           else{
              arr[k++] = b[j++];
           }

       }

       while(i<an){
          arr[k++] = a[i++];
       }
       while(j<bn){
          arr[k++] = b[j++];
       }
}
void MergeSortAlgo(int*arr,int l,int r){
    if(l>=r){
          return;
    }
    else{
          int mid = (l+r)/2;
          MergeSortAlgo(arr,l,mid);
          MergeSortAlgo(arr,mid+1,r);
          Merge(arr,l,mid,r); 
    }
}
int main(){
    int arr[8] = {9,2,6,4,7,5,1,1};

    MergeSortAlgo(arr,0,7);

    for(int i = 0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}  