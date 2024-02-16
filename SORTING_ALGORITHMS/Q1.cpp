#include<iostream>
using namespace std;
int PartialAlgo(int*num,int first,int last){
     int i = first-1,j = first;
     for(;j<last;j++){
        if(num[j]<num[last]){
          i++;
         int temp =  num[i];
         num[i] = num[j];
         num[j] = temp;
        }
     }
     i++;
     int temp =  num[i];
     num[i] = num[j];
     num[j] = temp;
     return i;

}
int QuickSort(int *num,int first,int last,int k){
     if(k>0 && k<=last-first+1){
      int  pi =  PartialAlgo(num,first,last);
       if(pi-first==k-1){
            return pi;
         }
        else if(pi-first>k-1){
            return QuickSort(num,first,pi-1,k);
        }
        else{
              return  QuickSort(num,pi+1,last,k-pi+first-1);
        }
     }
}
int main(){
    int N;
    cout<<"Enter the size of array:";
    cin>>N;
    int num[N];
    for(int i = 0;i<N;i++){
        cin>>num[i];
    }
    int k;
    cout<<"Enter the K value:";
    cin>>k;
    cout<<"The"<<k<<"th smallest number is :"<<num[QuickSort(num,0,N-1,k)];
}