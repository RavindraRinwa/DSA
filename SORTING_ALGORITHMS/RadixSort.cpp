#include<iostream>
#include<vector>
using namespace std;
void countSort(int*arr,int pos,int n){
    int idx[10] = {0};
    vector<int>ans(6);
    for(int i = 0;i<n;i++){
        idx[(arr[i]/pos)%10]++;
    }
    for(int i = 1;i<10;i++){
        idx[i]+=idx[i-1];
    }
    for(int i = n-1;i>=0;i--){
        ans[--idx[(arr[i]/pos)%10]] = arr[i];
    }
     for(int i = 0;i<6;i++){
         arr[i] = ans[i];
       }
}
void RadixSort(int*arr,int n){
    int max = -1;
    for(int i = 0;i<n;i++){
        if(max<arr[i]){
           max =arr[i];
        }
    }

        for(int pos  = 1;max/pos>0;pos*=10){
            countSort(arr,pos,n);
        }
    
}
int main(){
    int arr[6] = {170,45,75,90,802,2};
    RadixSort(arr,6);
    for(int i = 0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}