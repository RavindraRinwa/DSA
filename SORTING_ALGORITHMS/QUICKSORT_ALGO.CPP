#include<iostream>
using namespace std;
int partionAlgo(int arr[],int first,int last){
    int i = first-1,j=first;
    for(;j<last;j++){
         if(arr[j]<arr[last]){
             i++;
             int temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;
         }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return i;
    
}
void QuickSortAlgo(int*arr,int first,int last){
     if(first>=last){
            return ;
     }
     else{
         int pi = partionAlgo(arr,first,last);
         QuickSortAlgo(arr,first,pi-1);
         QuickSortAlgo(arr,pi+1,last);
     }
}
int main(){
   int arr[6] = {4,5,9,8,7,6};
   QuickSortAlgo(arr,0,5);

   for(int i = 0;i<6;i++){
     cout<<arr[i]<<" ";
   }
}