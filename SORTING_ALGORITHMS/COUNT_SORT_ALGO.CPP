#include<iostream>
using namespace std;
void CountSort(int*arr,int n){
    int max = -1;
    int ans[n];
    for(int i = 0;i<n;i++){
        if(max<arr[i]){
           max =arr[i];
        }
    }
    int idx[max+1] = {0};
    for(int i = 0;i<n;i++){
         idx[arr[i]]++;
    }
    for(int i = 1;i<=max;i++){
        idx[i]+=idx[i-1];
    }

    for(int i = n-1 ;i>=0;i--){
      ans[--idx[arr[i]]] = arr[i];
    }
    for(int i = 0;i<5;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int arr[5] = {5,2,2,3,1};
    
    CountSort(arr,5);
}
    