#include<iostream>
using namespace std;
void heapifyAlgo(int*arr,int i,int n){
     
     int largest = i;
     int left = 2*i;
     int right = 2*i+1;

     if(left<=n && arr[largest] < arr[left]){
        largest = left;
     }

     if(right<=n && arr[largest] < arr[right]){
        largest = right;
     }

     if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifyAlgo(arr,largest,n);
     }
     else{
        return ;
     }
}
void HeapSort(int*arr,int n){

    while(n>1){
        // first swape last element with first element
        swap(arr[1],arr[n]);

        //decerese the size
        n--;

        //put first element at correct position using heapify
        heapifyAlgo(arr,1,n);
        
    }

    return ;

}
int main(){
    int arr[6] = {-1,70,60,30,40,50};
    int n = 5;
    HeapSort(arr,n);
    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}